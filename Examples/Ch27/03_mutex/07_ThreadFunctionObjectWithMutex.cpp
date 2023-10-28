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
			lock_guard lock{ ms_mutex };
			cout << format("Counter {} has value {}", m_id, i) << endl;
		}
	}

private:
	int m_id{ 0 };
	int m_numIterations{ 0 };
	inline static mutex ms_mutex;
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

