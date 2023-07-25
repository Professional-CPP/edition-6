import oned_grid;

int main()
{
	OneDGrid<int> singleDGrid;
	OneDGrid<OneDGrid<int>> twoDGrid;
	OneDGrid<OneDGrid<OneDGrid<int>>> threeDGrid;

	singleDGrid[3] = 5;
	twoDGrid[3][3] = 5;
	threeDGrid[3][3][3] = 5;
}
