import std;

using namespace std;

int main()
{
	vector<int> intVector1 = { 1, 2, 3, 4, 5, 6 };
	vector<int> intVector2{ 1, 2, 3, 4, 5, 6 };
	vector intVector3{ 1, 2, 3, 4, 5, 6 };

	println("Vector 1 elements: {}", intVector1);
	println("Vector 2 elements: {}", intVector2);
	println("Vector 3 elements: {}", intVector3);
}
