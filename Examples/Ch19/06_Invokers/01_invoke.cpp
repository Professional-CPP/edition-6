import std;

using namespace std;

void printMessage(string_view message)
{
	println("{}", message);
}

int main()
{
	invoke(printMessage, "Hello invoke.");
	invoke([](const auto& msg) { println("{}", msg); }, "Hello invoke.");
	string msg{ "Hello invoke." };
	println("{}", invoke(&string::size, msg));
}
