import std;

using namespace std;

// Function template to populate a container of ints.
// A constraint enforces that the container supports push_back(int).
template<typename Container>
	requires requires(Container& c, int i) { c.push_back(i); }
void populateContainer(Container& cont)
{
	while (true) {
		print("Enter a number (0 to stop): ");
		int value;
		cin >> value;
		if (value == 0) {
			break;
		}
		cont.push_back(value);
	}
}

class SumAndProduct
{
public:
	void operator()(int value)
	{
		m_sum += value;
		m_product *= value;
	}

	int getSum() const { return m_sum; }
	int getProduct() const { return m_product; }

private:
	int m_sum{ 0 };
	int m_product{ 1 };
};

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	SumAndProduct calculator;
	calculator = for_each(cbegin(myVector), cend(myVector), calculator);
	// Or:
	//for_each(cbegin(myVector), cend(myVector), ref(calculator));
	println("The sum is {}", calculator.getSum());
	println("The product is {}", calculator.getProduct());
}
