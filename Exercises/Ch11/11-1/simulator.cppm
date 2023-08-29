export module simulator;

import std;

export namespace Simulator
{
	class CarSimulator
	{
	public:
		CarSimulator() { std::println("CarSimulator::CarSimulator()"); }
	};

	class BikeSimulator
	{
	public:
		BikeSimulator() { std::println("BikeSimulator::BikeSimulator()"); }
	};
}
