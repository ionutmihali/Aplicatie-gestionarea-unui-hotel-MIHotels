#pragma once
#include "IException.h"

class AbsException
	: public IException
{
protected:
	std::string msg;
	int cod;

public:
	AbsException(std::string msg) : msg(msg), cod(0) {}

	std::string getMsg() { return this->msg; }
	int getCod() { return this->cod; }
};

