#pragma once

#include <string>

class ICar
{
public:
	virtual ~ICar() = default;  // Always a virtual destructor!
	virtual std::string info() const = 0;
};
