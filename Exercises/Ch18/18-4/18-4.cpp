import std;

using namespace std;

double average(span<const double> values)
{
	double sum{ 0.0 };
	for (auto& value : values) {
		sum += value;
	}
	return sum / values.size();
}

int main()
{
	vector values1{ 1.1, 2.2, 3.3, 4.4 };
	println("{}", average(values1));

	array values2{ 1.1, 2.2, 3.3, 4.4 };
	println("{}", average(values2));
	println("{}", average({ values2.data() + 2, 2 }));
}
