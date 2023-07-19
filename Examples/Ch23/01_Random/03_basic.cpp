import std;

using namespace std;

int main()
{
	random_device seeder;
	mt19937 engine{ seeder() };

	uniform_int_distribution<int> distribution{ 1, 99 };
	println("{}", distribution(engine));
}

