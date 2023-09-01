import std;

using namespace std;

[[noreturn]] void forceProgramTermination()
{
	exit(1);  // Defined in <cstdlib>
}

bool isDongleAvailable()
{
	bool isAvailable{ false };
	// Check whether a licensing dongle is available...
	return isAvailable;
}

bool isFeatureLicensed(int featureId)
{
	if (!isDongleAvailable()) {
		// No licensing dongle found, abort program execution!
		forceProgramTermination();
	} else {
		// Dongle available, perform license check of the given feature...
		bool isLicensed{ featureId == 42 };
		return isLicensed;
	}
}

int main()
{
	bool isLicensed{ isFeatureLicensed(42) };
	println("{}", isLicensed);
}