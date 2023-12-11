import std;

using namespace std;

int main()
{
	vector<double> doubleVector; // Create a vector with zero elements.

	// Initialize max to smallest number.
	double max{ -numeric_limits<double>::infinity() };

	for (size_t i{ 1 }; true; ++i) {
		double value;
		print("Enter score {} (-1 to stop): ", i);
		cin >> value;
		if (value == -1) {
			break;
		}
		doubleVector.push_back(value);
		if (value > max) {
			max = value;
		}
	}

	max /= 100.0;
	for (auto& element : doubleVector) {
		element /= max;
		print("{} ", element);
	}
	println("");
}
