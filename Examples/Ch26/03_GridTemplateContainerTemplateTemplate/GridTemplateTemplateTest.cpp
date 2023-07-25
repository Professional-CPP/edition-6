import grid;
import std;

using namespace std;

int main()
{
	Grid<int, vector> myGrid;
	myGrid.at(1, 2) = 3;
	println("{}", myGrid.at(1, 2).value_or(0));

	Grid<int, vector> myGrid2{ myGrid };

	Grid<int, deque> myDequeGrid;
}
