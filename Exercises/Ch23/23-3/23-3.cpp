import std;

using namespace std;

auto createDiceValueGenerator()
{
	random_device seeder;
	mt19937 engine{ seeder() };
	shuffle_order_engine<mt19937, 15> shuffledEngine{ engine };
	uniform_int_distribution<int> distribution{ 1, 6 };
	return bind(distribution, shuffledEngine);
}

int main()
{
	auto generator{ createDiceValueGenerator() };

	while (true)
	{
		print("Throw two dice? (y or n): ");
		char answer;
		cin >> answer;
		if (answer == 'n' || answer == 'N') {
			break;
		} else if (answer == 'y' || answer == 'Y') {
			auto dieValue1{ generator() };
			auto dieValue2{ generator() };
			println("{} & {}", dieValue1, dieValue2);
		} else {
			println("  Please answer with y or n.");
		}
	}
}

