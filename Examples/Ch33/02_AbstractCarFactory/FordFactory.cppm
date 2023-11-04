export module ford_factory;

export import icarfactory;
import icar; 
import ford;
import std;

export class FordFactory : public ICarFactory
{
public:
	std::unique_ptr<ICar> makeSuv() override { return std::make_unique<FordSuv>(); }
	std::unique_ptr<ICar> makeSedan() override { return std::make_unique<FordSedan>(); }
};
