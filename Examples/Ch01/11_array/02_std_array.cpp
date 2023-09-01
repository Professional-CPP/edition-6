import std;

using namespace std;

int main()
{
	array<int, 3> arr{ 9, 8, 7 };
	// array arr{ 9, 8, 7 };  // Using CTAD
	println("Array size = {}", arr.size());
	println("2nd element = {}", arr[1]);
}
