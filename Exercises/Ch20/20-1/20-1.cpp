import std;

using namespace std;

int main()
{
	// ranges::fill()
	{
		print("Enter a number: ");
		int number;
		cin >> number;

		vector<int> values(10);
		ranges::fill(values, number);

		println("ranges::fill(): {:n}", values);
	}

	// std::fill()
	{
		print("Enter a number: ");
		int number;
		cin >> number;

		vector<int> values(10);
		std::fill(begin(values), end(values), number);

		println("std::fill(): {:n}", values);
	}
}