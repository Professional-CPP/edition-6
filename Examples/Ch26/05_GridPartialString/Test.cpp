import grid;
import std;

using namespace std;

int main()
{
	{
		Grid<int, 10, 10> myGrid;
		Grid<int, 10, 10> anotherGrid;

		myGrid.at(2, 3) = 45;
		anotherGrid = myGrid;

		println("{}", anotherGrid.at(2, 3).value_or(0));
	}

	{
		Grid<int, 2, 2> myIntGrid;				// Uses the original Grid
		Grid<const char*, 2, 2> myStringGrid;	// Uses the partial specialization
		// Grid<2, 3> test;						// DOES NOT COMPILE! No type specified.

		myStringGrid.at(1, 1) = "Hello";
		Grid<const char*, 2, 2> myStringGridCopy{ myStringGrid };
		myStringGridCopy.at(1, 1) = "World.";

		println("{}", myStringGrid.at(1, 1).value_or(""));
		println("{}", myStringGridCopy.at(1, 1).value_or(""));
	}
}
