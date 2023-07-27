import std;

using namespace std;

atomic_flag spinlock;
static const size_t NumberOfThreads{ 50 };
static const size_t LoopsPerThread{ 100 };

void dowork(size_t threadNumber, vector<size_t>& data)
{
	for (size_t i{ 0 }; i < LoopsPerThread; ++i) {
		while (spinlock.test_and_set()) {}  // Spins until lock is acquired.
		// Safe to handle shared data...
		data.push_back(threadNumber);
		spinlock.clear();                    // Releases the acquired lock.
	}
}

int main()
{
	vector<size_t> data;
	vector<jthread> threads;
	for (size_t i{ 0 }; i < NumberOfThreads; ++i) {
		threads.emplace_back(dowork, i, ref(data));
	}
	for (auto& t : threads) {
		t.join();
	}
	println("data contains {} elements, expected {}.", data.size(),
		NumberOfThreads * LoopsPerThread);
}
