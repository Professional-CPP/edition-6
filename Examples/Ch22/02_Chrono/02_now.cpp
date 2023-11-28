import std;

using namespace std;
using namespace std::chrono;

int main()
{
	// Set the global locale to the user's local (see Chapter 21).
	locale::global(locale{ "" });

	// Print the current UTC time.
	println("UTC: {:L}", system_clock::now());
	println("UTC: {:L%c}", system_clock::now());
}
