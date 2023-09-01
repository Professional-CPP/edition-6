import std;

using namespace std;

int main()
{
	pair<double, int> myPair{ 1.23, 5 };
	// pair myPair { 1.23, 5 };  // Using CTAD
	println("{} {}", myPair.first, myPair.second);
}
