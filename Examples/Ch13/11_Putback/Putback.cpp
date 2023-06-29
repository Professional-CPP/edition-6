import std;

using namespace std;

int main()
{
	char c;
	cin >> c;
	println("Retrieved {} before putback('e').", c);

	cin.putback('e');  // 'e' will be the next character read off the stream.
	cin >> c;
	println("Retrieved {} after putback('e').", c);
}
