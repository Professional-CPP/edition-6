import std;

using namespace std;

int main()
{
	array<int, 3> myArray{ 11, 22, 33 };
	println("{}", std::get<1>(myArray));
	// println("{}", std::get<10>(myArray));  // BUG! Compilation error!
}