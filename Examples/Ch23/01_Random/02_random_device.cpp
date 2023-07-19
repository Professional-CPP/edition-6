import std;

using namespace std;

int main()
{
	random_device rnd;
	println("Entropy: {}", rnd.entropy());
	println("Min value: {}, Max value: {}", rnd.min(), rnd.max());
	println("Random number: {}", rnd());
}
