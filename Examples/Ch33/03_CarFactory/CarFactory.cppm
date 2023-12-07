export module car_factory;

export import car;
import std;

export class CarFactory
{
public:
	virtual ~CarFactory() = default;  // Always a virtual destructor!
	CarFactory() = default;
	CarFactory(const CarFactory&) = default;
	CarFactory& operator=(const CarFactory&) = default;
	CarFactory(CarFactory&&) = default;
	CarFactory& operator=(CarFactory&&) = default;
	
	std::unique_ptr<ICar> requestCar()
	{
		// Increment the number of cars produced and return the new car.
		++m_numberOfCarsProduced;
		return createCar();
	}

	unsigned getNumberOfCarsProduced() const
	{
		return m_numberOfCarsProduced;
	}

private:
	virtual std::unique_ptr<ICar> createCar() = 0;
	unsigned m_numberOfCarsProduced{ 0 };
};

export class FordFactory final : public CarFactory
{
private:
	std::unique_ptr<ICar> createCar() override
	{
		return std::make_unique<Ford>();
	}
};

export class ToyotaFactory final : public CarFactory
{
private:
	std::unique_ptr<ICar> createCar() override
	{
		return std::make_unique<Toyota>();
	}
};
