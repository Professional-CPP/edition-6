import std;

using namespace std;

int main()
{
	vector<int> intVector(10);
	// other code...
	intVector.assign(5, 100);

	intVector.assign({ 1, 2, 3, 4 });

	vector<int> vectorOne(10);
	vector<int> vectorTwo(5, 100);

	vectorOne.swap(vectorTwo);
	// vectorOne now has 5 elements with the value 100.
	// vectorTwo now has 10 elements with the value 0
}
