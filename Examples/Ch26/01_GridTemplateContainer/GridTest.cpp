import grid;
import std;

using namespace std;

int main()
{
	Grid<int, vector<optional<int>>> myIntVectorGrid;
	Grid<int, deque<optional<int>>> myIntDequeGrid;

	myIntVectorGrid.at(3, 4) = 5;
	println("{}", myIntVectorGrid.at(3, 4).value_or(0));

	myIntDequeGrid.at(1, 2) = 3;
	println("{}", myIntDequeGrid.at(1, 2).value_or(0));

	Grid<int, vector<optional<int>>> grid2{ myIntVectorGrid };
	grid2 = myIntVectorGrid;

	//Grid<int, double> test; // WILL NOT COMPILE
}
