#pragma once

#include "ICar.h"
#include <memory>

class ICarFactory
{
public:
	virtual ~ICarFactory() = default;  // Always a virtual destructor!
	virtual std::unique_ptr<ICar> makeSuv() = 0;
	virtual std::unique_ptr<ICar> makeSedan() = 0;
};
