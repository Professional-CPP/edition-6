#pragma once

#include "ICarFactory.h"
#include "Toyota.h"
#include <memory>

class ToyotaFactory : public ICarFactory
{
public:
	std::unique_ptr<ICar> makeSuv() override { return std::make_unique<ToyotaSuv>(); }
	std::unique_ptr<ICar> makeSedan() override { return std::make_unique<ToyotaSedan>(); }
};
