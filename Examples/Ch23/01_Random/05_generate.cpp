import std;

using namespace std;

int main()
{
	random_device seeder;
	mt19937 engine{ seeder() };
	uniform_int_distribution<int> distribution{ 1, 99 };

	auto generator{ bind(distribution, engine) };
	
	vector<int> values(10);
	ranges::generate(values, generator);
	
	println("{:n}", values);
}

