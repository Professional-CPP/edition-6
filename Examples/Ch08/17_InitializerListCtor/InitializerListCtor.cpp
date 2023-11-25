import std;

using namespace std;

class EvenSequence
{
public:
	EvenSequence(initializer_list<double> values)
	{
		if (values.size() % 2 != 0) {
			throw invalid_argument{ "initializer_list should "
				"contain even number of elements." };
		}

		m_sequence.reserve(values.size());
		for (const auto& value : values) {
			m_sequence.push_back(value);
		}
		
		// Or:
		// m_sequence.assign(values);
	}

	void print() const
	{
		for (const auto& value : m_sequence) {
			std::print("{}, ", value);
		}
		println("");
	}
private:
	vector<double> m_sequence;
};

int main()
{
	try {
		EvenSequence p1{ 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };
		p1.print();

		EvenSequence p2 { 1.0, 2.0, 3.0 };
	} catch (const invalid_argument& e) {
		println("{}", e.what());
	}
}