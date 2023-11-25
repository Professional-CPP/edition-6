export module simulator:bike;

import std;
import :internals;

export namespace Simulator
{
	class BikeSimulator
	{
	public:
		BikeSimulator()
		{
			std::println("BikeSimulator::BikeSimulator()");
		}

		void setOdometer(double miles)
		{
			double km{ convertMilesToKm(miles) };
			std::println("{}", km);
		}
	};
}
