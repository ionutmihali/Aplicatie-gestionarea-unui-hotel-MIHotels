#pragma once
#include "AbsException.h"
class LogareException :
    public AbsException
{
public:
    LogareException(std::string msg) : AbsException(msg) { this->cod = 1; }
};

