#pragma once
#include "Cazare.h"
#include "LogareUtilizator.h"

class MIHotels
{
public:
	void afis();
	void meniu_utilizatori(Cazare& c, LogareUtilizator& l, int& f, string u);
	void meniu_administrator(Cazare& c, int& f);
	void Control();
};

