#include<iostream>
#include "../lib/lib.h"

using namespace std;


int main()
{
	int accion;
	
	cout<<	"Bienvenido al programa de gestion de pacientes para consultorios medicos.";
	cout << '\n';
	GetData();

	bool i=true;

	while (i){
	
	
	cout<<	"\nInserte el numero de la accion a ejecutar: ";
	cout<< "\n-------------------------------------------------------------------------------------------------";
	cout<< "\n1- Registrar nuevo paciente.";
	cout<< "\n2- Eliminar paciente por numero de historia clinica.";
	cout<< "\n3- Cambiar estado de paciente.";
	cout<< "\n4- Modificar los datos: edad y motivo de consulta.";
	cout<< "\n5- Mostrar orden de los pacientes (ordenados por prioridad y orden de llegada)";
	cout<< "\n6- Mostrar estadisticas.";
	cout<< "\n7- Guardar datos (Se recomienda seleccionar esta opción ANTES de salir del programa.)";
	cout<< "\n8- Revisar Paciente(Por ID)";
	cout<< "\n9- Salir\n";
	cin >> accion;
	int ID;
	switch (accion){
		case 1:
			RegistPatient();
			break;
		
		case 2: 
			cout<<"Ingrese el numero de la historia clinica del paciente : ";
			
			cin>> ID;
			DeletePatient(ID);
			break;
		
		case 3: cout<<"\nIngrese el numero de la historia clinica del paciente: ";
			
			cin>> ID;
		AttendedPatient(ID);
		break;
		
		case 4: {
			cout << "\nIngrese el numero de la historia clinica del paciente: ";
			int ID;
			cin >> ID;
			cout << "Ingrese los nuevos datos: ";
			int nuevaEdad;
			string nuevoMotivo;
			cout << "\nEdad: "; cin >> nuevaEdad;
			cout << "Motivo: "; cin.ignore(); getline(cin, nuevoMotivo);
			ModifyData(nuevaEdad, nuevoMotivo, ID);
			break;
		}
		case 5:
			PrintPatientWaitList();
			break;
		
		case 6: 
			PrintStats();
			break;
		
		case 7: SaveData();
		break;
		case 8:
			cout << "Ingrese el numero de la historia clinica del paciente : ";

			cin >> ID;
			SeeReason(ID);
			break;
		case 9: i= false;
		break;
		
		default: cout<<"\nNumero de accion erroneo.";
		break;  	
	}
}
	cout << "\nGracias por usar el sistema.";

return 0;
}

