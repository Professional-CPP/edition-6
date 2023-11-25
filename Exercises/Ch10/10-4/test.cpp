import hr;
import std;

using namespace std;

int main()
{
	HR::Employee employee{ 123, "Carlie", "Dudley" };
	println("{}", employee.toString());

	// Promote employee to manager.
	HR::Manager manager{ employee };
	println("{}", manager.toString());

	// Promote employee to director.
	HR::Director director{ employee };
	println("{}", director.toString());

	// Promote manager to director.
	HR::Director directorFromManager{ manager };
	println("{}", directorFromManager.toString());
}
