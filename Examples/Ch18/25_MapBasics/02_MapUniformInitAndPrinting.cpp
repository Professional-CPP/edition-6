import std;

using namespace std;

int main()
{
	map<string, int> m{
		{ "Marc G.", 12 },
		{ "Warren B.", 34 },
		{ "Peter V.W.", 56 }
	};

	for (const auto& p : m) {
		println("{} = {}", p.first, p.second);
	}

	println("");

	println("{}", m);
}
