import std;

using namespace std;

int main()
{
	{
		auto nextNumber{ [counter = 0] () mutable { return ++counter; } };

		vector<int> values(10);
		ranges::generate(values, nextNumber);
		println("Vector contains {:n}", values);

		print("Four more next numbers: ");
		for (unsigned i{ 0 }; i < 4; ++i) {
			print("{}, ", nextNumber());
		}

		println("");
	}

	println("");

	// Passing a reference to the lambda expression.
	{
		auto nextNumber{ [counter = 0] () mutable { return ++counter; } };

		vector<int> values(10);
		ranges::generate(values, ref(nextNumber));
		println("Vector contains {:n}", values);

		print("Four more next numbers: ");
		for (unsigned i{ 0 }; i < 4; ++i) {
			print("{}, ", nextNumber());
		}

		println("");
	}
}