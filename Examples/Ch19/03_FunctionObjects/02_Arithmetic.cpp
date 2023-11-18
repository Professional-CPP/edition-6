import std;

using namespace std;

template <input_iterator Iter, copy_constructible StartValue,
	invocable<const StartValue&, const StartValue&> Operation>
auto accumulateData(Iter begin, Iter end, const StartValue& startValue, Operation op)
{
	auto accumulated{ startValue };
	for (Iter iter{ begin }; iter != end; ++iter) {
		accumulated = op(accumulated, *iter);
	}
	return accumulated;
}

double geometricMean(span<const int> values)
{
	auto mult{ accumulateData(cbegin(values), cend(values), 1, multiplies<int>{}) };
	return pow(mult, 1.0 / values.size());
}

// Using transparent operator functor
double geometricMeanTransparent(span<const int> values)
{
	auto mult{ accumulateData(cbegin(values), cend(values), 1, multiplies<>{}) };
	return pow(mult, 1.0 / values.size());
}

int main()
{
	plus<int> myPlus;
	int res{ myPlus(4, 5) };
	println("{}", res);

	vector<int> myVector;

	while (true) {
		print("Enter a test score to add (0 to stop): ");
		int score;
		cin >> score;
		if (score == 0) {
			break;
		}
		myVector.push_back(score);
	}

	println("The geometric mean is {}", geometricMean(myVector));
	println("The geometric mean is (transparent function object) {}",
		geometricMeanTransparent(myVector));

	{
		vector<int> values{ 1, 2, 3 };
		double result{ accumulateData(cbegin(values), cend(values), 1.1, multiplies<>{}) };
		println("{}", result);
	}

	{
		vector<int> values{ 1, 2, 3 };
		double result{
			accumulateData(cbegin(values), cend(values), 1.1, multiplies<int>{}) };
		println("{}", result);
	}
}
