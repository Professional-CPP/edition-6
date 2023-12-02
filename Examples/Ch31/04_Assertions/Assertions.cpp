import std;
#include <cassert>

using namespace std;

void process(const vector<int>& coordinate)
{
	//assert(coordinate.size() == 3);

	assert(("A custom message...", coordinate.size() == 3));
	
	//assert(!"This should never happen.");
	
	// ...
}

int main()
{
	process({ 1, 2, 3 });
	process({ 1, 2 });
}
