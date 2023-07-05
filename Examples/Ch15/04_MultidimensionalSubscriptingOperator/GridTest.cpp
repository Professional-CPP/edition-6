import grid;
import std;

using namespace std;

int main()
{
	Grid<int> myIntGrid{ 4, 4 };

	int counter{ 0 };
	for (size_t y{ 0 }; y < myIntGrid.getHeight(); ++y) {
		for (size_t x{ 0 }; x < myIntGrid.getWidth(); ++x) {
			myIntGrid[x, y] = ++counter;
		}
	}

	for (size_t y{ 0 }; y < myIntGrid.getHeight(); ++y) {
		for (size_t x{ 0 }; x < myIntGrid.getWidth(); ++x) {
			print("{:3} ", myIntGrid[x, y].value_or(0));
		}
		println("");
	}
}
