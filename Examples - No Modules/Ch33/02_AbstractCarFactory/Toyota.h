#pragma once

#include "ICar.h"
#include <string>

class Toyota : public ICar
{
};

class ToyotaSedan : public Toyota
{
public:
	std::string info() const override { return "Toyota Sedan"; }
};

class ToyotaSuv : public Toyota
{
public:
	std::string info() const override { return "Toyota SUV"; }
};
