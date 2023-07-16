import std;

using namespace std;

int main()
{
	vector<string> myVector{ "", "one", "", "two", "three", "four" };

	println("{:n}", myVector);
	erase_if(myVector, [](const string& str) { return str.empty(); });
	println("{:n}", myVector);
}
