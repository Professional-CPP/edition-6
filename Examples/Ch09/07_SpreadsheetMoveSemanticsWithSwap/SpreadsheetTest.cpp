import std;
import spreadsheet;

using namespace std;

Spreadsheet createObject()
{
	return Spreadsheet { 3, 2 };
}

int main()
{
	vector<Spreadsheet> vec;
	for (size_t i{ 0 }; i < 2; ++i) {
		println("Iteration {}", i);
		vec.push_back(Spreadsheet { 100, 100 });
		println("");
	}

	Spreadsheet s { 2, 3 };
	s = createObject();

	println("");

	Spreadsheet s2 { 5, 6 };
	s2 = s;
}
