#pragma once
#include <string>

class IException
{
public:
	virtual std::string getMsg() = 0;
	virtual int getCod() = 0;
};

