import std;

using namespace std;

int main()
{
	{ // Assign
		vector<int> intVector(10);
		println("intVector: {:n}", intVector);  // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		// other code...
		intVector.assign(5, 100);
		println("intVector: {:n}", intVector);  // 100, 100, 100, 100, 100

		intVector.assign({ 1, 2, 3, 4 });
		println("intVector: {:n}", intVector);  // 1, 2, 3, 4
	}

	{// Swap
		vector<int> vectorOne(10);
		vector<int> vectorTwo(5, 100);
		println("vectorOne: {:n}", vectorOne);  // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
		println("vectorTwo: {:n}", vectorTwo);  // 100, 100, 100, 100, 100

		vectorOne.swap(vectorTwo);

		println("vectorOne: {:n}", vectorOne);  // 100, 100, 100, 100, 100
		println("vectorTwo: {:n}", vectorTwo);  // 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	}
}
