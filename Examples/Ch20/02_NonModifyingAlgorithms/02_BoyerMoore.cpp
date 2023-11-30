import std;

using namespace std;

int main()
{
	// Boyer-Moore searcher
	string text{ "This is the haystack to search a needle in." };
	string toSearchFor{ "needle" };
	boyer_moore_searcher searcher{ cbegin(toSearchFor), cend(toSearchFor) };
	auto result{ search(cbegin(text), cend(text), searcher) };
	if (result != cend(text)) {
		println("Found the needle.");
	} else {
		println("Needle not found.");
	}
}
