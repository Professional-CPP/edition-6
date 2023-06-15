import std;

using namespace std;

// rvalue reference parameter
void handleMessage(string&& message)
{
	println("handleMessage with rvalue reference: {}", message);
}

int main()
{
	string a{ "Hello " };
	handleMessage(auto{ a });
}