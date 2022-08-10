#pragma once
#include "AbsException.h"
class RezervareException :
    public AbsException
{
public:
    RezervareException(std::string msg) : AbsException(msg) { this->cod = 3; }
};

