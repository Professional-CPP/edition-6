import std;

int main()
{
	// Copy list initialization
	auto a = { 11 };         // initializer_list<int>
	auto b = { 11, 22 };     // initializer_list<int>

	// Direct list initialization
	auto c{ 11 };           // int
	//auto d{ 11, 22 };       // Error, too many elements.
}
