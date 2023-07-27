import std;

using namespace std;

int k;
thread_local int n;

void threadFunction(int id)
{
	println("Thread {}: k={}, n={}", id, k, n);
	++n;
	++k;
}

int main()
{
	thread t1{ threadFunction, 1 };
	t1.join();

	thread t2{ threadFunction, 2 };
	t2.join();
}