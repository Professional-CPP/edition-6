import std;

using namespace std;

int main()
{
	vector<double> doubleVector(10); // Create a vector of 10 doubles.

	// Initialize max to smallest number.
	double max{ -numeric_limits<double>::infinity() };

	for (size_t i{ 0 }; i < doubleVector.size(); ++i) {
		print("Enter score {}: ", i + 1);
		cin >> doubleVector[i];
		if (doubleVector[i] > max) {
			max = doubleVector[i];
		}
	}

	max /= 100.0;
	for (auto& element : doubleVector) {
		element /= max;
		print("{} ", element);
	}
	println("");
}
