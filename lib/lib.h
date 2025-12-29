#pragma once

using namespace std;

struct Patient
{
    int Age;
    int ID;
    string names;
    string Reason;
    string priority;
    string status;
};

//Modifyng stuff
void RegistPatient();

void DeletePatient(int ID);

void AttendedPatient(int ID);

void ModifyData(int NewAge, string Reason, int ID);
//Lists
void PrintPatientWaitList();

void PrintStats();
//Data Storage
void SaveData();

void LoadData();

void GetData();

void EraseData();