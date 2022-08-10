#include <iostream>
using namespace std;
#include "MIHotels.h"
#include "IException.h"

int main()
{
	try {
		MIHotels m;
		m.Control();
		return 0;
	}

	catch (IException& ex)
	{
		std::cout << ex.getMsg() << std::endl << "Eroare cod: " << ex.getCod() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown error" << std::endl;
	}
}