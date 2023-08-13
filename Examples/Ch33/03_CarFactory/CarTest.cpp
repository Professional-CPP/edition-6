import car_factory;
import std;

using namespace std;

class LeastBusyFactory : public CarFactory
{
public:
	// Constructs an instance, taking ownership of the given factories.
	explicit LeastBusyFactory(vector<unique_ptr<CarFactory>>&& factories);

protected:
	unique_ptr<ICar> createCar() override;

private:
	vector<unique_ptr<CarFactory>> m_factories;
};

LeastBusyFactory::LeastBusyFactory(vector<unique_ptr<CarFactory>>&& factories)
	: m_factories{ move(factories) }
{
	if (m_factories.empty()) {
		throw runtime_error{ "No factories provided." };
	}
}

unique_ptr<ICar> LeastBusyFactory::createCar()
{
	CarFactory* bestSoFar{ m_factories[0].get() };

	for (auto& factory : m_factories) {
		if (factory->getNumberOfCarsProduced() <
			bestSoFar->getNumberOfCarsProduced()) {
			bestSoFar = factory.get();
		}
	}

	return bestSoFar->requestCar();
}

int main()
{
	ToyotaFactory myFactory;
	auto myCar{ myFactory.requestCar() };
	println("{}", myCar->info());    // Outputs Toyota

	println("------------");


	vector<unique_ptr<CarFactory>> factories;

	// Create 3 Ford factories and 1 Toyota factory. 
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<FordFactory>());
	factories.push_back(make_unique<ToyotaFactory>());

	// To get more interesting results, preorder some cars.
	factories[0]->requestCar();
	factories[0]->requestCar();
	factories[1]->requestCar();
	factories[3]->requestCar();

	// Create a factory that automatically selects the least busy
	// factory from a list of given factories.
	LeastBusyFactory leastBusyFactory{ move(factories) };

	// Build 10 cars from the least busy factory.
	for (unsigned i{ 0 }; i < 10; ++i) {
		auto theCar{ leastBusyFactory.requestCar() };
		println("{}", theCar->info());
	}
}
