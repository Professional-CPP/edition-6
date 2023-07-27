import std;

using namespace std;

void initializeSharedResources()
{
	// ... Initialize shared resources to be used by multiple threads.

	println("Shared resources initialized.");
}

atomic<bool> g_initialized{ false };
mutex g_mutex;

void processingFunction()
{
	if (!g_initialized) {
		unique_lock lock{ g_mutex };
		if (!g_initialized) {
			initializeSharedResources();
			g_initialized = true;
		}
	}
	print("1");
}

int main()
{
	vector<jthread> threads;

	for (int i{ 0 }; i < 5; ++i) {
		threads.emplace_back(processingFunction);
	}

	// No need to manually call join(), as we are using jthread.
}
