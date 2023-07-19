import std;

using namespace std;

// Using the abbreviated function template syntax.
void fillVector(vector<int>& values, const auto& generator)
{
	ranges::generate(values, generator);
}

//template<invocable T>
//void fillVector(vector<int>& values, const T& generator)
//{
//	ranges::generate(values, generator);
//}

//void fillVector(vector<int>& values, const function<int()>& generator)
//{
//	ranges::generate(values, generator);
//}

int main()
{
	random_device seeder;
	mt19937 engine{ seeder() };
	uniform_int_distribution<int> distribution{ 1, 99 };

	auto generator{ bind(distribution, engine) };

	vector<int> values(10);
	fillVector(values, generator);

	println("{:n}", values);
}

