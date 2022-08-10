#include "MIHotels.h"
#include "LogareUtilizator.h"
#include "Cazare.h"
#include "LogareException.h"
#include "Log.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void MIHotels::afis()
{
	system("CLS");
	cout << "			  *** Bine ati venit pe MIHotels ***" << endl;
	cout << "			~Cazarea perfecta pentru tine este aici~" << endl;
	cout << endl;
	cout << endl;
	cout << "1. Logare utilizator" << endl;
	cout << "2. Logare administrator" << endl;
	cout << "3. Creare cont utilizator" << endl;
	cout << "4. Parasiti aplicatia" << endl;
	cout << endl;
}

void MIHotels::meniu_utilizatori(Cazare& c, LogareUtilizator& l, int& flag, string u)
{
	system("CLS");
	cout << "Bine ai venit, " << u << "!" << endl << endl;
	cout << "1. Cauta cazare" << endl;
	cout << "2. Rezervarile mele" << endl;
	cout << "3. Inapoi la meniul principal" << endl;
	cout << endl;

	int choice1 = 0;
	cout << "Introduceti numarul corespunzator optiunii dorite: ";
	cin >> choice1;
	if (choice1 == 1)
	{
		l.rezervare(c, u);
		l.setDiscout();
	}
	else if (choice1 == 2)
	{
		l.vezi_rezervari(c, u);
		int choice = 0;
		cout << endl << "Apasati 1 pentru a reveni la meniu: ";
		cin >> choice;
	}
	else if (choice1 == 3)
		flag = 1;
}

void MIHotels::meniu_administrator(Cazare& c, int& flag)
{
	system("CLS");
	cout << "Modul ADMIN activat! Bine ati venit, MIHALI!" << endl << endl;
	cout << "1. Adauga cazare" << endl;
	cout << "2. Cereri de rezervare" << endl;
	cout << "3. Statistici" << endl;
	cout << "4. Inapoi la meniul principal" << endl;
	cout << endl;

	int choice1 = 0;
	cout << "Introduceti numarul corespunzator optiunii dorite: ";
	cin >> choice1;
	if (choice1 == 1)
	{
		c.addCazare();
	}
	if (choice1 == 2)
	{
		c.acceptRezervare();
	}
	else if (choice1 == 3)
	{
		c.statistici();
	}
	else if (choice1 == 4)
		flag = 1;
}

void MIHotels::Control()
{
	LogareUtilizator l("ionutmihalii", "abcdefg");
	int choice = 5;
	Cazare c;
	c.addCazare("CasaDuca.txt");
	c.addCazare("HotelAro.txt");

	while (choice > 4)
	{
		afis();
		cout << "Introduceti numarul corespunzator optiunii dorite: ";
		cin >> choice;
		if (choice == 1)
		{
			system("CLS");
			int flag = 0;
			int ok = 0;
			int v = 0;
			string u;
			string p;
			while ( ok == 0)
			{
				if (v < 3)
				{
					cout << "Nume de utilizator: ";
					cin >> u;
					cout << "Parola: ";
					cin >> p;
					if (l.verificare(u, p) == 1)
						ok = 1;
					else
					{
						v++;
						Log::Alerta();
					}
				}
				else
				{
					Log::Eroare();
					throw LogareException("Ai gresit parola de prea multe ori!");
				}
			}

			while (flag == 0)
			{
				meniu_utilizatori(c, l, flag, u);
				choice = 5;
			}
		}
		else if (choice == 2)
		{
			int v = 0;
			int ok = 0;
			while (ok == 0)
			{
				if (v < 3)
				{
					string u;
					string p;
					system("CLS");
					cout << "Administrator: ";
					cin >> u;
					cout << "Parola: ";
					cin >> p;
					if (u == "adminMIH" && p == "cazare2022")
					{
						ok = 1;
					}
					else
					{
						system("CLS");
						cout << "Conectare esuata! Username sau parola gresita!" << endl;
						v++;
						Log::Alerta();
					}
				}
				else
				{
					Log::Eroare();
					throw LogareException("Ai gresit parola de prea multe ori!");
				}
			}

			int flag = 0;
			while (flag == 0)
			{
				meniu_administrator(c, flag);
				choice = 5;
			}

		}
		else if (choice == 3)
		{
			int ok = 0;
			string u;
			string p;
			while (ok == 0)
			{
				system("CLS");
				cout << "Nume de utilizator: ";
				cin >> u;
				cout << "Parola: ";
				cin >> p;
				if (l.verificaUser(u) == 1)
				{
					l.addUtilizator(u, p);
					ok = 1;
				}
			}

			int flag = 0;
			while (flag == 0)
			{
				meniu_utilizatori(c, l, flag, u);
				choice = 5;
			}
		}
		else if (choice == 4)
		{
			system("CLS");
			cout << "Speram ca v-am fost de folos in gasirea cazarii perfecte!" << endl;
			cout << "Va mai asteptam pe la noi!" << endl;
		}
		else if (choice > 4)
			cout << "Valoarea introdusa e prea mare. Reia!" << endl;
	}
}
