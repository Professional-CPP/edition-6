import std;

using namespace std;

template<typename... Values>
bool allEven(const Values&... values) { return ((values % 2 == 0) && ...); }

template<typename... Values>
bool anyEven(const Values&... values) { return ((values % 2 == 0) || ...); }

int main()
{
	println("{} {} {}", allEven(2, 4, 6), allEven(2, 3), allEven()); // true false true
	println("{} {} {}", anyEven(1, 2, 3), anyEven(1, 3), anyEven()); // true false false
}
