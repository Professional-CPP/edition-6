import std;

using namespace std;

class Counter
{
public:
	explicit Counter(int id, int numIterations)
		: m_id{ id }, m_numIterations{ numIterations }
	{
	}

	void operator()() const
	{
		for (int i{ 0 }; i < m_numIterations; ++i) {
			println("Counter {} has value {}", m_id, i);
		}
	}

private:
	int m_id{ 0 };
	int m_numIterations{ 0 };
};

int main()
{
	// Using uniform initialization syntax.
	thread t1{ Counter{ 1, 20 } };

	// Using named variable.
	Counter c{ 2, 12 };
	thread t2{ c };

	// Wait for threads to finish.
	t1.join();
	t2.join();
}
