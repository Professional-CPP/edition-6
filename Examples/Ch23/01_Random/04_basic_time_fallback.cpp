import std;

using namespace std;

int main()
{
	random_device seeder;

	const auto seed{ seeder.entropy() ? seeder() : time(nullptr) };

	mt19937 engine{ static_cast<mt19937::result_type>(seed) };

	uniform_int_distribution<int> distribution{ 1, 99 };
	println("{}", distribution(engine));
}

