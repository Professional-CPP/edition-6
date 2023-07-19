import std;

using namespace std;
using namespace std::chrono;

int main()
{
	// Set the global locale to the user's local (see Chapter 21).
	locale::global(locale{ "" });

	auto date{ 2020y / June / 22d };
	println("{:L} was a {:L%A}", date, weekday{ date });
}
