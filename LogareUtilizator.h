#pragma once
#include <string>
using namespace std;
#include "Cazare.h"

class LogareUtilizator
{
private:
	string* username;
	string* parola;
	int nr = 0;
	int discount = 0;


public:
	LogareUtilizator(string u, string p);
	void setDiscout();

	void addUtilizator(string u, string p);
	int verificare(string u, string p);
	int verificaUser(string u);
	void printListUtilizatori();
	void rezervare(Cazare& c, string u);
	void vezi_rezervari(Cazare& c, string u);
};

