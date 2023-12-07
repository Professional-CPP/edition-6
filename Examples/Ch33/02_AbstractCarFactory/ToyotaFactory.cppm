export module toyota_factory;

export import icarfactory;
import icar;
import toyota;
import std;

export class ToyotaFactory : public ICarFactory
{
public:
	std::unique_ptr<ICar> makeSuv() override { return std::make_unique<ToyotaSuv>(); }
	std::unique_ptr<ICar> makeSedan() override { return std::make_unique<ToyotaSedan>(); }
};
