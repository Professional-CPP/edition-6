import car_factory;
import std;

using namespace std;

class LeastBusyFactory final : public CarFactory
{
public:
	// Constructs an instance, taking ownership of the given factories.
	explicit LeastBusyFactory(vector<unique_ptr<CarFactory>> factories);

private:
	unique_ptr<ICar> createCar() override;
	vector<unique_ptr<CarFactory>> m_factories;
};

LeastBusyFactory::LeastBusyFactory(vector<unique_ptr<CarFactory>> factories)
	: m_factories{ move(factories) }
{
	if (m_factories.empty()) {
		throw runtime_error{ "No factories provided." };
	}
}

unique_ptr<ICar> LeastBusyFactory::createCar()
{
	auto leastBusyFactory{ ranges::min_element(m_factories,
		[](const auto& factory1, const auto& factory2) {
			return factory1->getNumberOfCarsProduced() < factory2->getNumberOfCarsProduced(); }) };
	return (*leastBusyFactory)->requestCar();
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

	// To get more interesting results, preorder some cars from specific factories.
	for (size_t i : {0, 0, 0, 1, 1, 2}) {
		factories[i]->requestCar();
	}

	// Create a factory that automatically selects the least busy
	// factory from a list of given factories.
	LeastBusyFactory leastBusyFactory{ move(factories) };

	// Build 10 cars from the least busy factory.
	for (unsigned i{ 0 }; i < 10; ++i) {
		auto theCar{ leastBusyFactory.requestCar() };
		println("{}", theCar->info());
	}
}
