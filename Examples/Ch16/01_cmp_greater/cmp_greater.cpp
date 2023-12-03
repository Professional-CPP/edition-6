import std;

using namespace std;

int main()
{
	println("{}", (-1 > 0u));            // true
	println("{}", cmp_greater(-1, 0u));  // false
}
