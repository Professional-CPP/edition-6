import std;

using namespace std;

const size_t BufferSize{ 1024 };

int main()
{
	println("Enter a line of text:");
	char buffer[BufferSize]{ 0 };
	cin.getline(buffer, BufferSize);
	println("\"{}\"", buffer);

	println("");

	println("Enter another line of text:");
	string myString;
	getline(cin, myString);
	println("\"{}\"", myString);
}
