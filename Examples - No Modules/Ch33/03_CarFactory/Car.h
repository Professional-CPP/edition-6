#pragma once

#include <string>

class ICar
{
public:
	virtual ~ICar() = default;  // Always a virtual destructor!
	virtual std::string info() const = 0;
};

class Ford : public ICar
{
public:
	std::string info() const override { return "Ford"; }
};

class Toyota : public ICar
{
public:
	std::string info() const override { return "Toyota"; }
};
