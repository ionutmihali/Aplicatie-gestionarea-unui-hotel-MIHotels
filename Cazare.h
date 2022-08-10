#pragma once
#include <string>
#include <fstream>
using namespace std;

typedef struct camera {
	int nr_camere = 0;
	int nr_loc[10] = { 0 };
	int pret[10] = { 0 };
	int disponibilitate[10] = { 0 };
	int nr_zile = 0;
	int perioada[10] = { 0 };
	string u[10];
}camera;

class Cazare
{
private:
	char* unitate[30];
	char* oras[30];
	camera cam[30];
	int masa[30] = { 0 };
	int type[30] = { 0 };
	int sm[30] = { 0 };
	int nr_unitati = 0;

	int nr_rezervari[30] = { 0 };
	double grad_ocup[30] = { 0 };

public:
	Cazare();

	void addCazare();
	void addCazare(const char*);

	void afisare_unitati();
	void afisare_facilitati(int index, int d, string u);

	void efectRezervare(int, int, string);
	void veziRezervari(string u);
	void acceptRezervare();

	int pretRezervare(int, int, int, int, int);

	void vezi_recenzii(int);
	void ofera_recenzie(int, string);

	void statistici();
	void top();
	void sortare(char* a[]);
	void ocupare();
};

