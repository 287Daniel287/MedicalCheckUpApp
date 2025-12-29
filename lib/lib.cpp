#include "lib.h"
#include<iostream>
#include<vector>
#include<fstream>
#include<chrono>
#include<thread>
using namespace std;
static vector<Patient> Pacientes;
//Modifyng stuff
void RegistPatient()
{
    Patient newPatient;
    cout << "\n Ingrese los nombres y apellidos del paciente: ";
    cin.ignore();
    getline(cin, newPatient.names);
    for (Patient p : Pacientes)
    {
        if (p.names == newPatient.names)
        {
            cout << "El nombre ingresado ya existe, chequee los datos!\n";
            return RegistPatient();
        }
        
    }
    cout << "Ingrese la edad del paciente: ";
    cin >> newPatient.Age;
    if (newPatient.Age > 100 || newPatient <= 0)
    {
        cout << "La Edad Ingresada no es valida, chequee los datos!\n";
        return RegistPatient();
    }
    cout << "Ingrese el numero de historia del paciente: ";
    cin >> newPatient.ID;
    cin.ignore();
    cout << "Motivo de la consulta: ";
    getline(cin, newPatient.Reason);
    cin.ignore();
    cout << "Prioridad(1-Urgente,2-Normal): ";
    cin >> newPatient.priority;
    if (newPatient.priority < 1 || newPatient > 2)
    {
        cout << "Ese tipo de Urgencia no es valida, chequee los datos!\n";
        return RegistPatient();
    }
    newPatient.status = "En Espera";
    Pacientes.push_back(newPatient);
    cout << "Paciente Guardado con exito!\n";
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}

void DeletePatient(int ID)
{
    Pacientes[ID].erase();
    cout << "Paciente Eliminado con exito!";
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}
void AttendedPatient(int RequestedID)
{
    for (Patient p : Pacientes)
    {
        if (p.ID == RequestedID) p.status = "Atendido";
    }
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}

void ModifyData(int NewAge, string NewReason, int RequestedID)
{
    for (Patient p : Pacientes)
    {
        if (p.ID == RequestedID)
        {
            p.Age = NewAge;
            p.Reason = NewReason;
            break;
        }
    }
    this_thread::sleep_for(chrono::seconds(2));
    system("cls");
}
//Lists
void PrintPatientWaitList()
{
    printf("%s%20s%10s", "ID", "Nombre","Prioridad")
    for(Patient p : Pacientes)
    {
        if(p.priotiy == "Urgente" && p.status != "Atendido")
        {
            printf("%d%20s%10s", p.ID, p.names, p.priority);
        }
    }
    for(Patient p : Pacientes)
    {
        if(p.priotiy == "Normal" && p.status != "Atendido")
        {
            printf("%d%20s%10s", p.ID, p.names, p.priority);
        }
    }
    cout << "\n presione espacio para continuar..";
    cin.get();
    this_thread::sleep_for(chrono::milliseconds(300));
    system("cls");
}

void PrintStats()
{
    int atendidos = 0, espera = 0, urgentes = 0;
    printf("%s%10s%10s", "Atendidos", "En Espera", "Urgentes");
    cout << "\n";
    for(Patient p : Pacientes)
    {
        if (p.status == "En Espera")espera++;
        else atendidos++;

        if (p.priority == "Urgente")urgentes++;
    }
    printf("%d%10d%10d", atendidos, espera, urgentes);
    cout << "\n presione espacio para continuar..";
    cin.get();
    this_thread::sleep_for(chrono::milliseconds(300));
    system("cls");
}
//Data Storage
void SaveData()
{

}

void LoadData()
{
    
}
void EraseData()
{
    std::ofstream archivo("Datos.txt", std::ios::trunc);
}
void GetData()
{

}