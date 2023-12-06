import nd_grid;
import std;

using namespace std;

int main()
{
	NDGrid<int, 3> my3DGrid{ 4 };
	my3DGrid[2][1][2] = 5;
	my3DGrid[1][1][1] = 5;

	println("{}", my3DGrid[2][1][2]);
}
