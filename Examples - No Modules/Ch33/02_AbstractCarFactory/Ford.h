#pragma once

#include "ICar.h"
#include <string>

class Ford : public ICar
{
};

class FordSedan : public Ford
{
public:
	std::string info() const override { return "Ford Sedan"; }
};

class FordSuv : public Ford
{
public:
	std::string info() const override { return "Ford SUV"; }
};
