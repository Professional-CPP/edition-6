import std;

using namespace std;

void printVec(const vector<int>& arr)
{
	for (int i : arr) {
		print("{} ", i);
	}
	println("");
} 

struct OddsAndEvens { vector<int> odds, evens; };

OddsAndEvens separateOddsAndEvens(const vector<int>& arr)
{
	vector<int> odds, evens;
	for (int i : arr) {
		if (i % 2 == 1) {
			odds.push_back(i);
		} else {
			evens.push_back(i);
		}
	}
	return OddsAndEvens{ .odds = odds, .evens = evens };
}

int main()
{
	vector<int> vecUnSplit{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	auto oddsAndEvens{ separateOddsAndEvens(vecUnSplit) };
	printVec(oddsAndEvens.odds);
	printVec(oddsAndEvens.evens);
}
