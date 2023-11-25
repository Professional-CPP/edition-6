import std;

using namespace std;

int main()
{
	// A vector to store all values.
	vector<double> values;

	// Ask the user to enter values until 0 is entered.
	println("Input values, one at a time followed by Enter. 0 to stop:");
	while (true) {
		double value;
		cin >> value;
		if (value == 0.0) {
			break;
		}
		values.push_back(value);
	}

	// Format the values in a table with a couple of columns.
	for (auto value : values) {
		println("{0:16e} | {0:12f} | {0:<12g} | {0:#>+12g}", value);
	}
}
