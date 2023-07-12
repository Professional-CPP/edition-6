import std;

using namespace std;

int main()
{
	vector<double> doubleVector;

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

	for (vector<double>::iterator iter{ begin(doubleVector) };
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		print("{} ", *iter);
	}
	println("");

/*
	// Using auto keyword
	for (auto iter{ begin(doubleVector) };
		iter != end(doubleVector); ++iter) {
		*iter /= max;
		print("{} ", *iter);
	}
	println("");
*/
}
