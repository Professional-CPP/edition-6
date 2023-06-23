import grid;
import std;

using namespace std;

constexpr size_t getHeight()
{
	return 10;
}

int main()
{
	Grid<int, 10, 10> myGrid;
	Grid<int, 10, 10> anotherGrid;

	myGrid.at(2, 3) = 42;
	anotherGrid = myGrid;

	println("{}", anotherGrid.at(2, 3).value_or(0));

	const size_t height{ 10 };
	Grid<int, 10, height> testGrid;

	Grid<double, 2, getHeight()> myDoubleGrid;
}
