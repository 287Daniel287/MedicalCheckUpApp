#include "lib.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
#include<thread>
#include <sstream>
#include <conio.h>
using namespace std;

static vector<Patient> Pacientes;
//Modifyng stuff
void RegistPatient()
{
    Patient newPatient;
    cout << "Ingrese los nombres y apellidos del paciente: ";
    cin.ignore();
    getline(cin, newPatient.names);
    for (Patient &p : Pacientes)
    {
        if (p.names == newPatient.names)
        {
            cout << "El nombre ingresado ya existe, chequee los datos!\n";
            return RegistPatient();
        }
        
    }
    cout << "Ingrese la edad del paciente: ";
    cin >> newPatient.Age;
    if (newPatient.Age > 100 || newPatient.Age <= 0)
    {
        cout << "La Edad Ingresada no es valida, chequee los datos!\n";
        return RegistPatient();
    }
    cout << "Ingrese el numero de historia del paciente: ";
    cin >> newPatient.ID;
    for (Patient& p : Pacientes)
    {
        if (p.ID == newPatient.ID)
        {
            cout << "La ID ingresada ya existe, chequee los datos!\n";
            return RegistPatient();
        }

    }
    cin.ignore();
    cout << "Motivo de la consulta: ";
    getline(cin, newPatient.Reason);
    cout << "Prioridad(1-Urgente,2-Normal): ";
    int prior;
    cin >> prior;
    if (prior == 1) newPatient.priority = "Urgente";
    else if (prior == 2) newPatient.priority = "Normal";
    else { cout << "Ese tipo de urgencia no es v�lido, chequee los datos!\n"; return RegistPatient(); }
    newPatient.status = "En Espera";
    Pacientes.push_back(newPatient);
    cout << "Paciente Guardado con exito!\n";
    cout << "\npresione cualquier tecla para continuar..";
    _getch();
    system("cls");
}

void DeletePatient(int RequestedID)
{
    
    for (auto it = Pacientes.begin(); it != Pacientes.end(); ++it) 
    { 
        if (it->ID == RequestedID) 
        {
            Pacientes.erase(it); 
            cout << "Paciente eliminado con exito!\n";
            _getch();
            system("cls");
            return; 
        } 
    } 
    cout << "No se encontro paciente con ese ID.\n";
    _getch();
    system("cls");
}
void AttendedPatient(int RequestedID)
{
    for (Patient &p : Pacientes)
    {
        if (p.ID == RequestedID) p.status = "Atendido";
    }
    cout << "El paciente con la id " << RequestedID << " fue atendido";
    cout << "\npresione cualquier tecla para continuar..";
    _getch();
    system("cls");
}

void ModifyData(int NewAge, string NewReason, int RequestedID)
{
    for (Patient &p : Pacientes)
    {
        if (p.ID == RequestedID)
        {
            p.Age = NewAge;
            p.Reason = NewReason;
            break;
        }
    }
    cout << "Datos modificados con exito!\n";
    cout << "\npresione cualquier tecla para continuar..";
    _getch();
    system("cls");
}
//Lists
void PrintPatientWaitList()
{
    printf("%s%30s%10s\n", "ID", "Nombre", "Prioridad");
    for(Patient p : Pacientes)
    {
        if(p.priority == "Urgente" && p.status != "Atendido")
        {
            printf("%d%30s%10s\n", p.ID, p.names.c_str(), p.priority.c_str());
        }
    }
    for(Patient p : Pacientes)
    {
        if(p.priority == "Normal" && p.status != "Atendido")
        {
            printf("%d%30s%10s", p.ID, p.names.c_str(), p.priority.c_str());
        }
    }
    cout << "\npresione cualquier tecla para continuar..";
    _getch();
    system("cls");
}

void PrintStats()
{
    int atendidos = 0, espera = 0, urgentes = 0;
    printf("%s%10s%10s", "Atendidos", "En Espera", "Urgentes");
    cout << "\n";
    for(Patient &p : Pacientes)
    {
        if (p.status == "En Espera")espera++;
        else atendidos++;

        if (p.priority == "Urgente")urgentes++;
    }
    printf("%d%10d%10d", atendidos, espera, urgentes);
    cout << "\npresione cualquier tecla para continuar..";
    _getch();
    system("cls");
}

void SeeReason(int RequestedID)
{
    for (Patient& p : Pacientes)
    {
        if (p.ID == RequestedID) 
        {
            cout <<"Nombre: " << p.names
                << '\n'
                << "Edad: " << p.Age
                << '\n'
                << "ID: " << p.ID
                << '\n'
                << "Motivo: " << p.Reason
                << '\n'
                << "Prioridad: " << p.priority
                << '\n'
                << "Estado: " << p.status;
            break;
        }
    }
    cout << "\npresione cualquier tecla para continuar..";
    _getch();
    system("cls");
}
//Data Storage
void SaveData()
{
    ofstream archivo("Datos.txt", ios::out);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo para guardar.\n"; 
        return;
    }
    for (const Patient& p : Pacientes) { 
        archivo << p.ID << ";" 
                << p.names << ";" 
                << p.Age << ";" 
                << p.Reason << ";" 
                << p.priority << ";" 
                << p.status << "\n"; 
    }
    archivo.close(); 
    cout << "Datos guardados correctamente.\n";
    _getch();
    system("cls");
}

void LoadData()
{
    ifstream archivo("Datos.txt");
    if (!archivo.is_open()) {
        cout << "No hay archivo de datos.\n";
        return;
    }

    Pacientes.clear();

    string linea; while (getline(archivo, linea)) {
        if (linea.empty()) continue;

        Patient p; stringstream ss(linea); string campo;
        getline(ss, campo, ';');
        p.ID = stoi(campo);
        getline(ss, p.names, ';');
        getline(ss, campo, ';'); p.Age = stoi(campo);
        getline(ss, p.Reason, ';');
        getline(ss, p.priority, ';');
        getline(ss, p.status, ';');

        Pacientes.push_back(p);
    }
    archivo.close();

    if (!Pacientes.empty()) cout << "Se cargaron " << Pacientes.size() << " pacientes desde archivo.\n"; 
    
    else cout << "El archivo estaba vacio.\n";
}
void EraseData()
{
    ofstream archivo("Datos.txt", ios::trunc); 
    archivo.close(); 
    Pacientes.clear(); 
    cout << "Datos eliminados.\n";
}
void GetData()
{
    ifstream archivo("Datos.txt"); 
    if (!archivo.is_open()) 
    { 
        cout << "No existe archivo de datos.\n"; 
        return; 
    } 
    bool tieneDatos = archivo.peek() != ifstream::traits_type::eof(); 
    archivo.close(); 
    if (tieneDatos) 
    { 
        cout << "Hay datos guardados. Desea cargarlos (C) o eliminarlos (E)? "; 
        char opcion; 
        cin >> opcion; 
        if (opcion == 'C' || opcion == 'c') LoadData();  
        else if (opcion == 'E' || opcion == 'e') EraseData();  
    }
    else cout << "No hay datos guardados.\n"; 
}