import std;

using namespace std;

double divideNumbers(double numerator, double denominator)
{
	if (denominator == 0) {
		throw invalid_argument{ "Denominator cannot be 0." };
	}
	return numerator / denominator;
}

int main()
{
	try {
		println("{}", divideNumbers(2.5, 0.5));
		println("{}", divideNumbers(2.3, 0));
		println("{}", divideNumbers(4.5, 2.5));
	} catch (const invalid_argument& exception) {
		println("Exception caught: {}", exception.what());
	}
}
