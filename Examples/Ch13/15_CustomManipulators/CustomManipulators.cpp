import std;

using namespace std;

// Custom tab manipulator.
ostream& tab(ostream& stream)
{
	return stream << '\t';
}

int main()
{
	cout << "Test" << tab << "!" << endl;
}
