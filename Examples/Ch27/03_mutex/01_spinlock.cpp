import std;

using namespace std;

static constexpr unsigned NumberOfThreads{ 50 };
static constexpr unsigned LoopsPerThread{ 100 };

void dowork(unsigned threadNumber, vector<unsigned>& data, atomic_flag& spinlock)
{
	for (unsigned i{ 0 }; i < LoopsPerThread; ++i) {
		while (spinlock.test_and_set()) {} // Spins until lock is acquired.
		// Safe to handle shared data...
		data.push_back(threadNumber);
		spinlock.clear();                  // Releases the acquired lock.
	}
}

int main()
{
	vector<unsigned> data;
	atomic_flag dataSpinlock;
	vector<jthread> threads;
	for (unsigned i{ 0 }; i < NumberOfThreads; ++i) {
		threads.emplace_back(dowork, i, ref(data), ref(dataSpinlock));
	}
	for (auto& t : threads) {
		t.join();
	}
	println("data contains {} elements, expected {}.", data.size(),
		NumberOfThreads * LoopsPerThread);
}
