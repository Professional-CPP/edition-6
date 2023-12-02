import associative_array;
import std;

using namespace std;

int main()
{
	AssociativeArray<int> myArray;
	myArray["Key 1"] = 11;
	myArray["Key 2"] = 22;
	myArray["Key 3"] = 33;

	try {
		println("{}", myArray["Key 1"]);
		println("{}", myArray["Key 2"]);

		// Test const operator[]
		const AssociativeArray<int>& c{ myArray };
		println("{}", c["Key 3"]);
		println("{}", c["Key 4"]);
	} catch (const invalid_argument& ex) {
		println("Caught exception: {}", ex.what());
	}
}
