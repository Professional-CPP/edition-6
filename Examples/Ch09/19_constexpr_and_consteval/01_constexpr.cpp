import std;

using namespace std;

constexpr int getArraySize()
{
	return 32;
}

int main()
{
	{
		int myArray[getArraySize()];	 // OK
		println("Size of array = {}", size(myArray));
	}

	{
		int myArray[getArraySize() + 1]; // OK
		println("Size of array = {}", size(myArray));
	}
}
