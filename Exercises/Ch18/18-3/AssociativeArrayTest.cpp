import std;

using namespace std;

int main()
{
	unordered_map<string, int> myArray;
	myArray["Key 1"] = 11;
	myArray["Key 2"] = 22;
	myArray["Key 3"] = 33;

	println("{}", myArray["Key 1"]);
	println("{}", myArray["Key 2"]);

	//// std::unordered_map does not support operator[]
	//// on const instances.
	// Test const operator[]
	//const AssociativeArray<int>& c{ myArray };
	//println("{}", c["Key 3"]);
	//println("{}", c["Key 4"]);

	//// Instead, you can use find().
	const auto& c{ myArray };
	println("{}", c.find("Key 3")->second);
	auto res{ c.find("Key 4") };
	if (res == end(c)) {
		println("Key 4 not found.");
	}
}
