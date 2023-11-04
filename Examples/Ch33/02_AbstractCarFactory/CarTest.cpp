import ford_factory;
import toyota_factory;
import std;

using namespace std;

void createSomeCars(ICarFactory& carFactory)
{
	auto sedan{ carFactory.makeSedan() };
	auto suv{ carFactory.makeSuv() };
	println("Sedan: {}", sedan->info());
	println("SUV: {}", suv->info());
}

int main()
{
	FordFactory fordFactory;
	ToyotaFactory toyotaFactory;
	createSomeCars(fordFactory);
	createSomeCars(toyotaFactory);
}
