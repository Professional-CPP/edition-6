import std;

using namespace std;

char** allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray{ new char* [xDimension] }; // Allocate first dimension

	for (size_t i{ 0 }; i < xDimension; ++i) {
		myArray[i] = new char[yDimension];    // Allocate ith subarray
	}

	return myArray;
}

void releaseCharacterBoard(char**& myArray, size_t xDimension)
{
	for (size_t i{ 0 }; i < xDimension; ++i) {
		delete [] myArray[i];    //  Delete ith subarray
		myArray[i] = nullptr;
	}

	delete [] myArray;           //  Delete first dimension
	myArray = nullptr;
}

int main()
{
	const size_t xDimension{ 7 };
	const size_t yDimension{ 13 };
	char** board{ allocateCharacterBoard(xDimension, yDimension) };
	releaseCharacterBoard(board, xDimension);
}

