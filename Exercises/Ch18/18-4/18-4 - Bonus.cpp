import std;

using namespace std;

template <typename T> requires integral<T> || floating_point<T> // Type constraints: see Chapter 12
double average(span<const T> values)
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
	//// The parameter of the function template is span<const T>.
	//// This cannot be automatically deduced from the function arguments.
	//// So, we need to specify the template type argument explicitly.
	println("{}", average<double>(values1));

	array values2{ 1, 2, 3, 4 };
	println("{}", average<int>(values2));
	println("{}", average<int>({ values2.data() + 2, 2 }));
}
