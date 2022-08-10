#pragma once
#include "AbsException.h"
class MeniuException :
    public AbsException
{
public:
    MeniuException(std::string msg) : AbsException(msg) { this->cod = 2; }
};

