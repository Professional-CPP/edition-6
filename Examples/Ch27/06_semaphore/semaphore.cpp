import std;

using namespace std;

int main()
{
	counting_semaphore semaphore{ 4 };

	vector<jthread> threads;

	for (int i{ 0 }; i < 10; ++i) {
		threads.emplace_back([&semaphore, i] {
			semaphore.acquire();
			// ... Slot acquired ... (at most 4 threads concurrently)
			print("{}", i);
			this_thread::sleep_for(5s);
			semaphore.release();
		});
	}

	// No need to manually call join(), as we are using jthread.
}
