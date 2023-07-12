import std;

using namespace std;

int main()
{
	// Store the a words in the main dictionary.
	list<string> dictionary{ "aardvark", "ambulance" };

	// Store the b words.
	list<string> bWords{ "bathos", "balderdash" };

	// Add the c words to the main dictionary.
	dictionary.push_back("canticle");
	dictionary.push_back("consumerism");

	// Splice the b words into the main dictionary.
	if (!bWords.empty()) {
		// Get an iterator to the last b word.
		auto iterLastB{ --(cend(bWords)) };
		// Iterate up to the spot where we want to insert b words.
		auto it{ cbegin(dictionary) };
		for (; it != cend(dictionary); ++it) {
			if (*it > *iterLastB) {
				break;
			}
		}

		// Add in the b words. This action removes the elements from bWords.
		dictionary.splice(it, bWords);
	}

	// Print out the dictionary.
	println("{:n:}", dictionary);
}
