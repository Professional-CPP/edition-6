import hr;
import std;

using namespace std;

int main()
{
	HR::Person person{ "Otis", "Lowe" };
	HR::Employee employee{ 123, "John", "Doe" };
	HR::Manager manager{ 456, "Otis", "Lowe" };
	HR::Director director{ 46, "Fran", "Stone"};

	println("{}", person.toString());
	println("{}", employee.toString());
	println("{}", manager.toString());
	println("{}", director.toString());
}
