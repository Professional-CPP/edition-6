import std;

using namespace std;

int main()
{
	map<int, int> myMap{ { 4, 40 }, { 5, 50 }, { 6, 60 } };
	for_each_n(cbegin(myMap), 2, [](const auto& p)
		{ println("{} -> {}", p.first, p.second); });
}
