import std;

using namespace std;

void counter(int id, int numIterations)
{
	for (int i{ 0 }; i < numIterations; ++i) {
		println("Counter {} has value {}", id, i);
		//cout << format("Counter {} has value {}", id, i) << endl;
	}
}

int main()
{
	thread t1{ counter, 1, 6 };
	thread t2{ counter, 2, 4 };
	t1.join();
	t2.join();
}
