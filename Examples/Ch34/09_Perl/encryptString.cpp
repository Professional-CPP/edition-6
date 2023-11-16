import std;

using namespace std;

string encrypt(string_view input);

int main(int argc, char** argv)
{
	if (argc < 2) {
		println(cerr, "Usage: {} string-to-be-encrypted", argv[0]);
		return 1;
	}

	print("{}", encrypt(argv[1]));
} 

// Performs a very weak form of "encryption" by 
// adding 13 to each character of the string.
string encrypt(string_view input)
{
	string encrypted{ input.data() };
	for (auto& character : encrypted) {
		character += 13;
	}
	return encrypted;
}
