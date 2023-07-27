import logger;
import std;

using namespace std;

void logSomeMessages(int id, Logger& logger)
{
	for (int i{ 0 }; i < 10; ++i) {
		logger.log(format("Log entry {} from thread {}", i, id));
		this_thread::sleep_for(50ms);
	}
}

int main()
{
	Logger logger;

	vector<jthread> threads;
	// Create a few threads all working with the same Logger instance.
	for (int i{ 0 }; i < 10; ++i) {
		threads.emplace_back(logSomeMessages, i, ref(logger));
	}
}
