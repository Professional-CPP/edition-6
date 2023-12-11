import std;

using namespace std;

int main()
{
	array myArray{ 11, 22, 33 };  // std::array supports CTAD.
	println("{}", std::get<1>(myArray));
	// println("{}", std::get<10>(myArray));  // BUG! Compilation error!
}