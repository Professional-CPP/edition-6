export module simulator:car;

import std;
import :internals;

export namespace Simulator
{
	class CarSimulator
	{
	public:
		CarSimulator()
		{
			std::println("CarSimulator::CarSimulator()");
		}

		void setOdometer(double miles)
		{
			double km{ convertMilesToKm(miles) };
			std::println("{}", km);
		}
	};
}
