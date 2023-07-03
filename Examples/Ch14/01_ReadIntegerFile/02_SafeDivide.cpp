import std;

using namespace std;

double safeDivide(double num, double den)
{
	if (den == 0) {
		throw invalid_argument{ "Divide by zero" };
	}
	return num / den;
}

int main()
{
	try {
		println("{}", safeDivide(5, 2));
		println("{}", safeDivide(10, 0));
		println("{}", safeDivide(3, 3));
	} catch (const invalid_argument& e) {
		println("Caught exception: {}", e.what());
	}
}
