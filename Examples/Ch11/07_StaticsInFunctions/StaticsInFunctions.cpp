import std;

using namespace std;

void performTask()
{
	static bool initialized{ false };

	if (!initialized) {
		println("initializing");
		// Perform initialization.
		initialized = true;
	}

	// Perform the desired task.
}

int main()
{
	performTask();
	performTask();
}
