import std;

using namespace std;

int main()
{
	int id{ 1 };
	int numIterations{ 5 };
	thread t1{ [id, numIterations] {
		for (int i{ 0 }; i < numIterations; ++i) {
			println("Counter {} has value {}", id, i);
		}
	} };
	t1.join();
}
