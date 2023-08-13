export module iabstractCarFactory;

import icar;
import std;

export class IAbstractCarFactory
{
public:
	virtual ~IAbstractCarFactory() = default;  // Always a virtual destructor!
	virtual std::unique_ptr<ICar> makeSuv() = 0;
	virtual std::unique_ptr<ICar> makeSedan() = 0;
};
