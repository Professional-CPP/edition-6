import std;

using namespace std;

void increment(atomic<int>& counter)
{
	for (int i{ 0 }; i < 100; ++i) {
		++counter;
		this_thread::sleep_for(1ms);
	}
}

int main()
{
	atomic<int> counter{ 0 };
	vector<jthread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.emplace_back(increment, ref(counter));
	}

	for (auto& t : threads) {
		t.join();
	}

	println("Result = {}", counter.load());
}
