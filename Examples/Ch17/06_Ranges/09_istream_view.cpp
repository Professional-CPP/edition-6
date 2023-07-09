import std;

using namespace std;

int main()
{
	println("Type integers, an integer >= 5 stops the program.");
	for (auto value : ranges::istream_view<int>{ cin }
		| views::take_while([](const auto& v) { return v < 5; })
		| views::transform([](const auto& v) { return v * 2; })) {
		println("> {}", value);
	}
	println("Terminating...");
}
