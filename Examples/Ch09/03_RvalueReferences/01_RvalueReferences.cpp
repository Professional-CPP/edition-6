import std;

using namespace std;

void helper(string&& message)
{
}

// lvalue reference parameter
void handleMessage(string& message)
{
	println("handleMessage with lvalue reference: {}", message);
}

// rvalue reference parameter
void handleMessage(string&& message)
{
	println("handleMessage with rvalue reference: {}", message);
	helper(std::move(message));
}

int main()
{
	string a{ "Hello " };
	string b{ "World" };

	// Handle a named variable
	handleMessage(a);             // Calls handleMessage(string& value)

	// Handle an expression
	handleMessage(a + b);         // Calls handleMessage(string&& value)

	// Handle a literal
	handleMessage("Hello World"); // Calls handleMessage(string&& value)

	// Handle a named variable and force to use rvalue reference function
	handleMessage(std::move(b));  // Calls handleMessage(string&& value)
}
