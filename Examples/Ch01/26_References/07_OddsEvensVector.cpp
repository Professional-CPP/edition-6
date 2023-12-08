import std;

using namespace std;

void printVec(const vector<int>& arr)
{
	for (int i : arr) {
		print("{} ", i);
	}
	println("");
} 

void separateOddsAndEvens(const vector<int>& arr,
						  vector<int>& odds, vector<int>& evens)
{
	for (int i : arr) {
		if (i % 2 == 1) {
			odds.push_back(i);
		} else {
			evens.push_back(i);
		}
	}
}

int main()
{
	vector<int> vecUnSplit{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> odds, evens;

	separateOddsAndEvens(vecUnSplit, odds, evens);

	printVec(odds);
	printVec(evens);
}
