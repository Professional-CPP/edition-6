import std;

using namespace std;

int main()
{
	atomic<int> value{ 10 };
	println("Value = {}", value.load());
	int fetched{ value.fetch_add(4) };
	println("Fetched = {}", fetched);
	println("Value = {}", value.load());
}
