import std;

using namespace std;

int main()
{
	vector<int> vectorOne(10);
	vector<int> vectorTwo(10);

	if (vectorOne == vectorTwo) {
		println("equal!");
	} else {
		println("not equal!");
	}

	vectorOne[3] = 50;

	if (vectorOne < vectorTwo) {
		println("vectorOne is less than vectorTwo");
	} else {
		println("vectorOne is not less than vectorTwo");
	}
}
