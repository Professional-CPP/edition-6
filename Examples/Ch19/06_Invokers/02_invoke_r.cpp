//import std;
import std;

using namespace std;

int sum(int a, int b)
{
	return a + b;
}

int main()
{
	auto res1{ invoke(sum, 11, 22) };           // Type of res1 is int.
	auto res2{ invoke_r<double>(sum, 11, 22) }; // Type of res2 is double.
}
