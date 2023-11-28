import grid;

int main()
{
	Grid<int> myIntGrid{ 2, 2 };
	Grid<double> myDoubleGrid;
	myIntGrid.at(1, 1) = 11;

	myDoubleGrid = myIntGrid;
	Grid<double> newDoubleGrid{ myIntGrid };
}
