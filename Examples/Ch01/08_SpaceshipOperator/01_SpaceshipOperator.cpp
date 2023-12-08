import std;

using namespace std;

int main()
{
	int i{ 11 };
	strong_ordering result{ i <=> 0 };
	if (result == strong_ordering::less) { println("less"); }
	if (result == strong_ordering::greater) { println("greater"); }
	if (result == strong_ordering::equal) { println("equal"); }
}