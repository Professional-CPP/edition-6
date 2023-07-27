import std;

using namespace std;

int main()
{
	// Launch a number of threads to do some work.
	const size_t numberOfWorkerThreads{ 10 };
	latch latch{ numberOfWorkerThreads };
	vector<jthread> threads;
	for (int i{ 0 }; i < numberOfWorkerThreads; ++i) {
		threads.emplace_back([&latch, i] {
			// Do some work...
			print("{} ", i);
			this_thread::sleep_for(1s);
			print("{} ", i);

			// When work is done, decrease the latch counter.
			latch.count_down();
		});
	}
	// Wait for all worker threads to finish.
	latch.wait();
	println("\nAll worker threads are finished.");
}
