#define _CRT_SECURE_NO_WARNINGS
#include "Cazare.h"
#include "MeniuException.h"
#include "RezervareException.h"
#include "Log.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void print()
{
	cout << "Optiuni masa: " << endl;
	cout << "1. All inclusive" << endl;
	cout << "2. Mic dejun" << endl;
	cout << "3. Pranz" << endl;
	cout << "4. Cina" << endl;
};

Cazare::Cazare()
{
	unitate[nr_unitati] = new char[30];
	oras[nr_unitati] = new char[30];
	strcpy(unitate[nr_unitati], "");
	strcpy(oras[nr_unitati], "");
}

void Cazare::addCazare(const char* nume)
{
	FILE* f;
	char buffer[30];
	f = fopen(nume, "r");
	fgets(buffer, 30, f);
	char* p = strtok(buffer, "\n");
	unitate[nr_unitati] = new char[30];
	oras[nr_unitati] = new char[30];
	strcpy(unitate[nr_unitati], p);
	fgets(buffer, 30, f);
	p = strtok(buffer, "\n");
	strcpy(oras[nr_unitati], p);
	fgets(buffer, 30, f);
	cam[nr_unitati].nr_camere = atoi(buffer);
	for (int i = 0; i < cam[nr_unitati].nr_camere; i++)
	{
		fgets(buffer, 30, f);
		cam[nr_unitati].nr_loc[i] = atoi(buffer);
		fgets(buffer, 30, f);
		cam[nr_unitati].pret[i] = atoi(buffer);
	}
	
	fgets(buffer, 30, f);
	type[nr_unitati] = atoi(buffer);
	fgets(buffer, 30, f);
	sm[nr_unitati] = atoi(buffer);
	nr_unitati++;

	fclose(f);
}

void Cazare::addCazare()
{
	system("CLS");
	char buffer[30];
	unitate[nr_unitati] = new char[30];
	oras[nr_unitati] = new char[30];
	cout << "Nume unitate cazare: ";
	cin >> buffer;
	strcpy(unitate[nr_unitati], buffer);
	cout << "Oras: ";
	cin >> buffer;
	strcpy(oras[nr_unitati], buffer);
	cout << "Numar camere: ";
	cin >> buffer;
	cam[nr_unitati].nr_camere = atoi(buffer);
	for (int i = 0; i < cam[nr_unitati].nr_camere; i++)
	{
		cout << "Camera " << i + 1 << " numar locuri: ";
		cin >> buffer;
		cam[nr_unitati].nr_loc[i] = atoi(buffer);
		cout << "Pret camera: ";
		cin >> buffer;
		cam[nr_unitati].pret[i] = atoi(buffer);
	}
	
	cout << "1. Hotel" << endl;
	cout << "2. Pensiune" << endl;
	cout << "Alegerea ta: ";
	cin >> buffer;
	type[nr_unitati] = atoi(buffer);
	cout << "Numar stele/margarete: ";
	cin >> buffer;
	sm[nr_unitati] = atoi(buffer);
	nr_unitati++;
}

void Cazare::afisare_unitati()
{
	for (int i = 0; i < nr_unitati; i++)
		cout << i + 1 << ". " << unitate[i] << endl;
}

int Cazare::pretRezervare(int d, int w, int n, int i, int j)
{
	int pret = 0;

	if (cam[i].disponibilitate[j] == 1)
		if(w==1)
		{
			pret = pret + cam[i].pret[j] * n + 0.25 * cam[i].pret[j] * n - d / 100 * cam[i].pret[j] * n;
			if (masa[i] == 1)
				pret = pret + 100 * n;
			else if (masa[i] == 2)
				pret = pret + 30 * n;
			else if (masa[i] == 3)
				pret = pret + 40 * n;
			else if (masa[i] == 2)
				pret = pret + 50 * n;
		}
		else if(w==2)
		{
			pret = pret + cam[i].pret[j] * n - d / 100 * cam[i].pret[j] * n;
			if (masa[i] == 1)
				pret = pret + 100 * n;
			else if (masa[i] == 2)
				pret = pret + 30 * n;
			else if (masa[i] == 3)
				pret = pret + 40 * n;
			else if (masa[i] == 2)
				pret = pret + 50 * n;
		}
	return pret;
}

void Cazare::efectRezervare(int index, int d, string u)
{
	cout << endl;
	int aux = index - 1;
	int choice = 0;
	cout << "Rezerva camera: ";
	cin >> choice;
	if (cam[aux].disponibilitate[choice - 1] != 1)
	{
		cam[aux].disponibilitate[choice - 1] = 1;
		cam[aux].u[choice - 1] = u;

		int w = 0;
		cout << "1. Rezervare weekend" << endl;
		cout << "2. Rezervare in cursul saptamanii" << endl;
		cout << "Introduceti numarul corespunzator optiunii dorite: ";
		cin >> w;
		if (w > 2)
		{
			Log::Eroare();
			throw MeniuException("Nu exista optiunea selectata!");
		}

		int nr_zile = 0;
		cout << "Numar nopti cazare: ";
		cin >> nr_zile;

		int a = 0;
		print();
		cout << "Introduceti numarul corespunzator optiunii dorite: ";
		cin >> a;
		if (a > 4)
		{
			Log::Eroare();
			throw MeniuException("Nu exista optiunea selectata!");
		}
		else
			masa[aux] = a;

		int pret = pretRezervare(d, w, nr_zile, aux, choice - 1);
		cout << "Pretul cazarii este: " << pret << endl;
		nr_rezervari[aux]++;
	}
	else
	{
		Log::Rezervare();
		throw RezervareException("Camera a fost deja rezervata!");
	}
}

void Cazare::afisare_facilitati(int index, int d, string u)
{
	system("CLS");
	int aux = index - 1;
	cout << unitate[aux] << " se afla in " << oras[aux] << " si are urmatoarele facilitati: " << endl;

	if (type[aux] == 1)
		cout << "Hotel cu " << sm[aux] << " stele" << endl;
	else if (type[aux] == 2)
		cout << "Pensiune cu " << sm[aux] << " margarete" << endl;

	for (int i = 0; i < cam[aux].nr_camere; i++)
	{
		if (cam[aux].disponibilitate[i] == 0)
		{
			cout << "Camera " << i + 1 << " numar locuri: " << cam[aux].nr_loc[i] << endl;
			cout << "Pret camera: " << cam[aux].pret[i] << endl;
		}
		else if (cam[aux].disponibilitate[i] == 1)
		{
			cout << "Camera " << i + 1 << " numar locuri: " << cam[aux].nr_loc[i] << " -INDISPONIBILA: s-a efectuat o cerere de rezervare asupra acestei camere" << endl;
			cout << "Pret camera: " << cam[aux].pret[i] << endl;
		}
	}

	efectRezervare(index, d, u);
	int choice = 0;
	cout << endl << "Apasati 1 pentru a reveni la meniul de utilizator: ";
	cin >> choice;
}

void Cazare::veziRezervari(string u)
{
	cout << "Rezervarile dumneavoastra sunt: " << endl;
	for (int i = 0; i < nr_unitati; i++)
		for (int j = 0; j < cam[i].nr_camere; j++)
			if (cam[i].disponibilitate[j] == 1 && cam[i].u[j]==u)
			{
				cout << "Camera rezervata la: " << unitate[i] << endl;
				cout << "Statusul rezervarii: In asteptarea confirmarii" << endl;
			}
			else if (cam[i].disponibilitate[j] == 2 && cam[i].u[j] == u)
			{
				cout << "Camera rezervata la: " << unitate[i] << endl;
				cout << "Statusul rezervarii: Acceptata" << endl;
			}
			else if (cam[i].disponibilitate[j] == 3 && cam[i].u[j] == u)
			{
				cout << "Camera rezervata la: " << unitate[i] << endl;
				cout << "Statusul rezervarii: Refuzata" << endl;
			}
}

void Cazare::acceptRezervare()
{
	system("CLS");
	cout << "Cereri de rezervare: " << endl;

	int ok = 1;
	for (int i = 0; i < nr_unitati; i++)
		for (int j = 0; j < cam[i].nr_camere; j++)
			if (cam[i].disponibilitate[j] == 1)
			{
				cout << "Cerere rezervare de o camera la: " << unitate[i] << " din partea lui: " << cam[i].u[j] << endl;
				ok++;
				cout << "1. Accepta" << endl;
				cout << "2. Refuza" << endl;
				cout << "Introduceti numarul corespunzator optiunii dorite: ";
				cin >> ok;
				if (ok == 1)
					cam[i].disponibilitate[j] = 2;
				else if (ok == 2)
					cam[i].disponibilitate[j] = 0;
				else if (ok > 2)
				{
					Log::Eroare();
					throw MeniuException("Nu exista optiunea selectata!");
				}
			}

}

void Cazare::vezi_recenzii(int index)
{
	system("CLS");
	int aux = index - 1;
	char nume[30];
	strcpy(nume, "");
	strcpy(nume, unitate[aux]);
	strcat(nume, "_rez.txt");
	ifstream fin(nume);

	string buffer;

	getline(fin, buffer);
	if (buffer == "")
		cout << "Nu exista recenzii!";
	else
		cout << buffer << endl;

	while (getline(fin, buffer))
		cout << buffer << endl;

}

void Cazare::ofera_recenzie(int index, string u)
{
	system("CLS");
	int aux = index - 1;
	char nume[30];
	string buffer;
	strcpy(nume, "");
	strcpy(nume, unitate[aux]);
	strcat(nume, "_rez.txt");

	ofstream fout(nume, ios_base::app);
	cout << "Recenzia dumneavoastra: ";
	cin.get();
	getline(cin, buffer);
	fout << u << " a zis: ";
	fout << buffer << endl;

}

void Cazare::sortare(char* a[])
{
	for(int i=0; i<nr_unitati-1;i++)
		for(int j=i+1; j<nr_unitati; j++)
			if (nr_rezervari[i] < nr_rezervari[j])
			{
				char aux[30];
				strcpy(aux, "");
				strcpy(aux, a[i]);
				strcpy(a[i], a[j]);
				strcpy(a[j], aux);
			}
}

void Cazare::top()
{
	char** aux2 = new char*[nr_unitati + 1];
	for (int i = 0; i < nr_unitati; i++)
	{
		aux2[i] = new char[30];
		strcpy(aux2[i], "");
	}

	for (int i = 0; i < nr_unitati; i++)
	{
		strcpy(aux2[i], unitate[i]);
	}

	sortare(aux2);
	for (int i = 0; i < nr_unitati; i++)
	{
		for(int j=0;j<nr_unitati;j++)
			if (strcmp(aux2[i], unitate[j]) == 0)
			{
				cout << i + 1 << ". " << aux2[i] << " -" << nr_rezervari[j] << " rezervare(i)" << endl;
			}
	}

}

void Cazare::ocupare()
{
	for (int i = 0; i < nr_unitati; i++)
		grad_ocup[i] = 0;
	
	for(int i=0; i<nr_unitati;i++)
		for(int j=0; j<cam[i].nr_camere; j++)
			if (cam[i].disponibilitate[j] == 2)
			{
				grad_ocup[i] += (double)(100 / cam[i].nr_camere);
			}

	for (int i = 0; i < nr_unitati; i++)
		cout << i + 1 << ". " << unitate[i] << " ocupata: " << grad_ocup[i] << "%" << endl;
}

void Cazare::statistici()
{
	system("CLS");
	int choice = 0;
	cout << "1. Topul unitatilor" << endl;
	cout << "2. Gradul de ocupare" << endl;

	cout << "Introduceti numarul corespunzator optiunii dorite: ";
	cin >> choice;

	if (choice == 1)
	{
		int choice = 0;
		system("CLS");
		top();
		cout << endl << "Apasati 1 pentru a reveni la meniu: ";
		cin >> choice;
	}
	else if (choice == 2)
	{
		int choice = 0;
		system("CLS");
		ocupare();
		cout << endl << "Apasati 1 pentru a reveni la meniu: ";
		cin >> choice;
	}
	else if (choice > 2)
	{
		Log::Eroare();
		throw MeniuException("Nu exista optiunea selectata!");
	}
}
