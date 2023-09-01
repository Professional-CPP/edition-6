import std;

using namespace std;

int main()
{
	int i{ 11 };
	strong_ordering result{ i <=> 0 };
	if (is_lt(result)) { println("less"); }
	if (is_gt(result)) { println("greater"); }
	if (is_eq(result)) { println("equal"); }
}