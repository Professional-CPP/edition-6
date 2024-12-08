#include "Person.h"
#include <print>

using namespace std;

int main()
{
	Person person{ "John", "Doe" };

	string str{ person };
	println("{}", str);
}
