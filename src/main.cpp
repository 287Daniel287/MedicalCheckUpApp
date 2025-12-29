#include<iostream>
#include "../lib/lib.h"

using namespace std;

struct patient{
};
int main()
{
	int accion;
	
	cout<<	"Bienvenido al programa de gestión de pacientes para consultorios médicos.";
	
	if(LoaData()){
	cout<< "/n Se han detectado ficheros previos, desea cargarlos en el programa, S o N?";	
	char resp;
	cin>>resp;
	
	if(resp== 's' || resp=='S'){
		GetData();
	}else {
		EraseData();
	}
	};
	bool i=true;

	while (i){
	
	
	cout<<	"\n Inserte el número de la acción a ejecutar: ";
	cout<< "\n-------------------------------------------------------------------------------------------------"<<endl;
	cout<< "\n 1- Registrar nuevo paciente.";
	cout<< "\n 2- Eliminar paciente por número de historia clínica.";
	cout<< "\n 3- Cambiar estado de paciente.";
	cout<< "\n 4- Modificar los datos: edad y motivo de consulta.";
	cout<< "\n 5- Mostrar orden de los pacientes (ordenados por prioridad y orden de llegada)";
	cout<< "\n 6- Mostrar estadísticas.";
	cout<< "\n 7- Guardar datos (Se recomienda seleccionar esta opción ANTES de salir del programa.)";
	cout<< "\n 8- Salir";
	
	
	switch (accion){
		case 1:
			RegisPatient();
			break;
		
		case 2: cout<<"\n Ingrese el número de la historia clínica del paciente:";
			int ID;
			cin>> ID;
			DeletePatient(ID);
			break;
		
		case 3: cout<<"\n Ingrese el número de la historia clínica del paciente:";
			int ID;
			cin>> ID;
		AttendedPatient(ID);
		break;
		
		case 4: 
		cout<<"\n Ingrese el numero de la historia clinica del paciente:";
			int ID;
			cin>> ID;
		cout<<"\n Ingrese los nuevos datos";
		int nuevaEdad;
		string nuevoMotivo;
		cout<< "\n Edad"; cin>>nuevaEdad;
		cout<< "\n Motivo"; cin>>nuevoMotivo;
		ModifyData(ID);
		break;
		
		case 5: PrintPatientWaitingList();
		break;
		
		case 6: PrintStats();
		break;
		
		Case 7: SaveData();
		break;
		
		Case 8: i= false;
		break;
		
		default: cout<<"\n Número de acción erroneo.";
		break;  	
	}
}
cout<< "/n Gracias por usar el sistema."

return 0;
}

