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

double arithmeticMean(span<const int> values)
{
	double sum{ accumulate(cbegin(values), cend(values), 0.0) };
	return sum / values.size();
}

int product(int value1, int value2)
{
	return value1 * value2;
}

double geometricMean(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1, product) };
	return pow(mult, 1.0 / values.size());
}

double geometricMeanLambda(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1,
		[](int value1, int value2) { return value1 * value2; }) };
	return pow(mult, 1.0 / values.size());
}

double geometricMeanFunctor(span<const int> values)
{
	int mult{ accumulate(cbegin(values), cend(values), 1, multiplies<>{}) };
	return pow(mult, 1.0 / values.size());
}

int main()
{
	vector<int> myVector;
	populateContainer(myVector);

	println("The arithmetic mean is {}", arithmeticMean(myVector));
	println("The geometric mean is {}", geometricMean(myVector));
	println("The geometric mean (Lambda version) is {}", geometricMeanLambda(myVector));
	println("The geometric mean (multiplies<>) is {}", geometricMeanFunctor(myVector));
}
