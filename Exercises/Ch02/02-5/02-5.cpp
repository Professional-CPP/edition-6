import std;

using namespace std;

int main()
{
	// A vector to store all words.
	vector<string> words;

	// Ask the user to enter words until * is entered.
	println("Input words. * to stop:");
	while (true) {
		string word;
		cin >> word;
		if (word == "*") {
			break;
		}
		words.push_back(word);
	}

	// Find longest word.
	size_t longestWord{ 0 };
	for (const auto& word : words) {
		if (word.size() > longestWord) {
			longestWord = word.size();
		}
	}

	// Print words in columns. The width of the columns is
	// based on the length of the longest word.
	unsigned count{ 0 };
	for (const auto& word : words) {
		print("| {:^{}} ", word, longestWord);
		if (++count == 5) {
			println("|");
			count = 0;
		}
	}
	if (count != 0) {
		println("|");
	}
}
