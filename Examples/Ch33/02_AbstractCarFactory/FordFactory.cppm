export module ford_factory;

export import iabstractCarFactory;
import icar; 
import ford;
import std;

export class FordFactory : public IAbstractCarFactory
{
public:
	std::unique_ptr<ICar> makeSuv() override { return std::make_unique<FordSuv>(); }
	std::unique_ptr<ICar> makeSedan() override { return std::make_unique<FordSedan>(); }
};
