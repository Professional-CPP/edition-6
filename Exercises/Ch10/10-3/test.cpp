import hr;
import std;

using namespace std;

int main()
{
	vector<unique_ptr<HR::Person>> persons;
	persons.push_back(make_unique<HR::Person>("John", "Doe"));
	persons.push_back(make_unique<HR::Manager>(456, "Otis", "Lowe"));
	persons.push_back(make_unique<HR::Director>(46, "Fran", "Stone"));
	persons.push_back(make_unique<HR::Employee>(33, "Harper", "Jones"));

	for (const auto& person : persons) {
		println("{}", person->toString());
	}
}
