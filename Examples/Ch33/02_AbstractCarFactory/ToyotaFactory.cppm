export module toyota_factory;

export import iabstractCarFactory;
import icar;
import toyota;
import std;

export class ToyotaFactory : public IAbstractCarFactory
{
public:
	std::unique_ptr<ICar> makeSuv() override { return std::make_unique<ToyotaSuv>(); }
	std::unique_ptr<ICar> makeSedan() override { return std::make_unique<ToyotaSedan>(); }
};
