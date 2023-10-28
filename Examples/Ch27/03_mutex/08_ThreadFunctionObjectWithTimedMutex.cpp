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
			unique_lock lock{ ms_timedMutex, 200ms };
			if (lock) {
				cout << format("Counter {} has value {}", m_id, i) << endl;
			} else {
				// Lock not acquired in 200ms, skip output.
			}
		}
	}

private:
	int m_id{ 0 };
	int m_numIterations{ 0 };
	inline static timed_mutex ms_timedMutex;
};

int main()
{
	// Using uniform initialization syntax
	jthread t1{ Counter{ 1, 20 } };

	// Using named variable
	Counter c{ 2, 12 };
	jthread t2{ c };

	// No need to manually call join(), as we are using jthread.
}
