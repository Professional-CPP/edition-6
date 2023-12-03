import std;

using namespace std;

template <typename T>
class SelfDrivable : public T
{
public:
	void drive()
	{
		this->setSpeed(1.2);
	}
};

class Car
{
public:
	void setSpeed(double speed)
	{
		println("Car speed set to {}.", speed);
	}
};

class Truck
{
public:
	void setSpeed(double speed)
	{
		println("Truck speed set to {}.", speed);
	}
};

int main()
{
	SelfDrivable<Car> car;
	SelfDrivable<Truck> truck;
	car.drive();
	truck.drive();
}
