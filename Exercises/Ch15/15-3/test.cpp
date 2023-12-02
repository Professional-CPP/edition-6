import person;
import std;

using namespace std;

int main()
{
	Person person{ "John", "Doe" };

	string str{ person };
	println("{}", str);
}
