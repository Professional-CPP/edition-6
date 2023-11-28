import std;

using namespace std;

int getRandom(int min, int max)
{
	return static_cast<int>(rand() % (max + 1UL - min)) + min;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	
	println("{}", rand());

	println("{}", getRandom(1, 6));
}
