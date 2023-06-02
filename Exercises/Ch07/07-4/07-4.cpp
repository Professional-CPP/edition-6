import std;

using namespace std;

void fillWithM(string& text)
{
	for (auto& character : text) {
		character = 'm';
	}
}


int main()
{
	string hello{ "Hello world!" };
	println("Before: {}", hello);

	fillWithM(hello);

	println("After:  {}", hello);
}
