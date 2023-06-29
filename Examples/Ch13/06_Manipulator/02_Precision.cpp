import std;

using namespace std;

int main()
{
	// Use setprecision manipulator.
	cout << "This should be '1.2346': " << setprecision(5) << 1.23456789 << endl;

	// Use precision() member function
	cout.precision(5);
	cout << "This should be '1.2346': " << 1.23456789 << endl;
}
