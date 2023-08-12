import std;

using namespace std;

class SelfDrivable
{
public:
	void drive(this auto& self)
	{
		self.setSpeed(1.2);
	}
};

class Car : public SelfDrivable
{
public:
	void setSpeed(double speed)
	{
		println("Car speed set to {}.", speed);
	}
};

class Truck : public SelfDrivable
{
public:
	void setSpeed(double speed)
	{
		println("Truck speed set to {}.", speed);
	}
};

int main()
{
	Car car;
	Truck truck;
	car.drive();
	truck.drive();
}
