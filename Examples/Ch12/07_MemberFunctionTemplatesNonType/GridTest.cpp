import grid;

using namespace std;

int main()
{
	Grid<int, 2, 2> myIntGrid;
	Grid<double, 4, 4> myDoubleGrid;
	myIntGrid.at(1, 1) = 11;

	myDoubleGrid = myIntGrid;
	Grid<double> newDoubleGrid{ myIntGrid };
}
