import std;

using namespace std;

int main()
{
	vector<string> values{ "", "one", "", "two", "three", "four" };

	println("{:n}", values);
	erase_if(values, [](const string& str) { return str.empty(); });
	println("{:n}", values);
}
