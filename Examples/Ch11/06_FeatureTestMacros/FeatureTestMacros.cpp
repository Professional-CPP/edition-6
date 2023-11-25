import std;

using namespace std;

int main()
{
#ifdef __cpp_range_based_for
	println("Range-based for loops are supported!");
#else
	println("Bummer! Range-based for loops are NOT supported!");
#endif
}
