import std;

using namespace std;

int main()
{
	char c;
	cin >> c;
	println("Retrieved {}.", c);

	cin.putback('e');  // 'e' will be the next character read off the stream.
	println("Called putback('e').");
	
	while (cin >> c) {
		println("Retrieved {}.", c);
	}
}
