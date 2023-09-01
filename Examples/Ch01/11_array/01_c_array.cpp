import std;

int main()
{
	{
		int myArray[3];
		myArray[0] = 0;
		myArray[1] = 0;
		myArray[2] = 0;
	}

	{
		int myArray[3] = { 0 };
	}

	{
		int myArray[3] = {};
	}

	{
		int myArray[3]{};
	}

	{
		int myArray[]{ 1, 2, 3, 4 }; // The compiler creates an array of 4 elements.
	}

	{
		int myArray[3]{ 2 };
		std::size_t arraySize1{ std::size(myArray) };
		std::size_t arraySize2{ sizeof(myArray) / sizeof(myArray[0]) };
	}

	{
		char ticTacToeBoard[3][3];
		ticTacToeBoard[1][1] = 'o';
	}
}
