#include "LogareUtilizator.h"
#include "MeniuException.h"
#include "Log.h"
#include <iostream>
using namespace std;

LogareUtilizator::LogareUtilizator(string u, string p)
{
	this->username = new string[20];
	this->username[nr] = u;
	this->parola = new string[20];
	this->parola[nr] = p;
	nr++;
}

void LogareUtilizator::setDiscout()
{
	if (discount < 18 && discount + 2 < 18)
	{
		discount = discount + 2;
	}
}

void LogareUtilizator::addUtilizator(string u, string p)
{
	this->username[nr] = u;
	this->parola[nr] = p;
	nr++;
}

int LogareUtilizator::verificare(string u, string p)
{
	for (int i = 0; i < nr; i++)
		if (username[i] == u && parola[i] == p)
		{
			cout << "Conectare realizata cu succes! Bine ai venit, " << username[i] << "!" << endl;
			return 1;
		}

	cout << "Conectare esuata!" << endl << endl;
	return 0;
}

void LogareUtilizator::printListUtilizatori()
{
	cout << "Utilizatorii aplicatiei sunt: " << endl;
	for (int i = 0; i < nr; i++)
	{
		cout << "- " << username[i] << endl;
	}
}

int LogareUtilizator::verificaUser(string u)
{
	for (int i = 0; i < nr; i++)
		if (username[i] == u)
		{
			cout << "Username existent! Reia logarea!" << endl;
			return 0;
		}
		else
		{
			return 1;
		}
	return 0;
}

void LogareUtilizator::rezervare(Cazare& c, string u)
{
	system("CLS");
	int choice = 0, choice1 = 0;
	c.afisare_unitati();
	cout << "Alegerea ta: ";
	cin >> choice;

	system("CLS");
	cout << "1. Facilitati" << endl;
	cout << "2. Ofera recenzie" << endl;
	cout << "3. Recenzii" << endl;
	cout << "Introduceti numarul corespunzator optiunii dorite: ";
	cin >> choice1;
	if (choice1 == 1)
	{
		c.afisare_facilitati(choice, discount, u);
	}
	else if (choice1 == 3)
	{
		c.vezi_recenzii(choice);
		int choice2 = 0;
		cout << endl << "Apasati 1 pentru a reveni la meniu: ";
		cin >> choice2;
	}
	else if (choice1 == 2)
	{
		c.ofera_recenzie(choice, u);
		int choice2 = 0;
		cout << endl << "Apasati 1 pentru a reveni la meniu: ";
		cin >> choice2;
	}
	else if (choice1 > 3)
	{
		Log::Eroare();
		throw MeniuException("Nu exista optiunea selectata!");
	}

}

void LogareUtilizator::vezi_rezervari(Cazare& c, string u)
{
	system("CLS");
	c.veziRezervari(u);
}
