import simulator;

int main()
{
	using namespace Simulator;

	CarSimulator carSim;
	carSim.setOdometer(123);

	BikeSimulator bikeSim;
	bikeSim.setOdometer(12345.36);

	// The following does not compile as convertMilesToKm()
	// is an internal helper function, not exported from the
	// simulator module.
	//double km{ convertMilesToKm(2.0) };
}
