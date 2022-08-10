#define _CRT_SECURE_NO_WARNINGS
#include "Log.h"
#include <fstream>
#include <string.h>
using namespace std;

void Log::Eroare()
{
	char nume[30];
	strcpy(nume, "");
	strcpy(nume, "Actiuni.log");
	ofstream fout(nume, ios_base::app);
	fout << "EROARE: Programul a captat o exceptie!" << endl;
}

void Log::Alerta()
{
	char nume[30];
	strcpy(nume, "");
	strcpy(nume, "Actiuni.log");
	ofstream fout(nume, ios_base::app);
	fout << "ALERTA: Probleme la autentificare: username sau parola gresita!" << endl;
}

void Log::Rezervare()
{
	char nume[30];
	strcpy(nume, "");
	strcpy(nume, "Actiuni.log");
	ofstream fout(nume, ios_base::app);
	fout << "REZERVARE: Un utilizator a incercat sa rezerve de 2 ori aceeasi camera!" << endl;
}