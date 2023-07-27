import std;

using namespace std;

int main()
{
	latch startLatch{ 1 };
	vector<jthread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.emplace_back([&startLatch] {
			// Do some initialization... (CPU bound)

			// Wait until the latch counter reaches zero.
			startLatch.wait();

			// Process data...
		});
	}

	// Load data... (I/O bound)

	// Once all data has been loaded, decrement the latch counter
	// which then reaches zero and unblocks all waiting threads.
	startLatch.count_down();

	// No need to manually call join(), as we are using jthread.
}
