import std;

using namespace std;

class PowerSource
{
public:
	virtual void printType() = 0;
};

class GasolinePowerSource : public PowerSource
{
public:
	void printType() override { println("GasolinePowerSource"); }
	virtual void fillTank() { println("Gasoline tank filled up."); }
};

class ElectricalPowerSource : public PowerSource
{
public:
	void printType() override { println("ElectricalPowerSource"); }
	virtual void chargeBatteries() { println("Batteries charged."); }
};

class Car
{
public:
	virtual PowerSource& getFilledUpPowerSource() = 0;
};

class GasolineCar : public Car
{
public:
	//PowerSource& getFilledUpPowerSource() override
	GasolinePowerSource& getFilledUpPowerSource() override
	{
		m_engine.fillTank();
		return m_engine;
	}
private:
	GasolinePowerSource m_engine;
};

class ElectricalCar : public Car
{
public:
	//PowerSource& getFilledUpPowerSource() override
	ElectricalPowerSource& getFilledUpPowerSource() override
	{
		m_engine.chargeBatteries();
		return m_engine;
	}
private:
	ElectricalPowerSource m_engine;
};

int main()
{
	GasolineCar gc;
	gc.getFilledUpPowerSource().printType();

	println("");

	ElectricalCar ev;
	ev.getFilledUpPowerSource().printType();
}
