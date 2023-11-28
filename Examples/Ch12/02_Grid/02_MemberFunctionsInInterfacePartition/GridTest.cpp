import grid;
import spreadsheet_cell;
import std;

using namespace std;

void processIntGrid(Grid<int>& /*grid*/)
{
	// Body omitted for brevity
}

int main()
{
	Grid<int> myIntGrid; // declares a grid that stores ints,
						 // using default arguments for the constructor
	Grid<double> myDoubleGrid{ 11, 11 }; // declares an 11x11 Grid of doubles

	myIntGrid.at(0, 0) = 10;
	int x{ myIntGrid.at(0, 0).value_or(0) };

	Grid<int> grid2{ myIntGrid };  // Copy constructor
	Grid<int> anotherIntGrid;
	anotherIntGrid = grid2;      // Assignment operator

	//Grid test;   // WILL NOT COMPILE
	//Grid<> test; // WILL NOT COMPILE

	processIntGrid(myIntGrid);

	Grid<SpreadsheetCell> mySpreadsheet;
	SpreadsheetCell myCell{ 1.234 };
	mySpreadsheet.at(3, 4) = myCell;

	Grid<const char*> myStringGrid;
	myStringGrid.at(2, 2) = "hello";

	Grid<vector<int>> gridOfVectors;
	vector<int> myVector{ 1, 2, 3, 4 };
	gridOfVectors.at(5, 6) = myVector;

	auto myGridOnFreeStore { make_unique<Grid<int>>(2, 2) }; // 2x2 Grid on the free store
	myGridOnFreeStore->at(0, 0) = 10;
	int x2 { myGridOnFreeStore->at(0, 0).value_or(0) };
}

// Explicit class template instantiation.
template class Grid<string>;
