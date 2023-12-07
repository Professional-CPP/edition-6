import std;

using namespace std;

class Person
{
public:
	explicit Person(string first, string last)
		: m_firstName{ move(first) }, m_lastName{ move(last) } { }

	const string& getFirstName() const { return m_firstName; }
	const string& getLastName() const { return m_lastName; }
private:
	string m_firstName;
	string m_lastName;
};

ostream& operator<<(ostream& os, const Person& person)
{
	os << format("{} {}", person.getFirstName(), person.getLastName());
	return os;
}

template<input_iterator InputIter,
	output_iterator<iter_reference_t<InputIter>> OutputIter>
void myCopy(InputIter begin, InputIter end, OutputIter target)
{
	for (auto iter{ begin }; iter != end; ++iter, ++target) {
		*target = *iter;
	}
}

int main()
{
	vector persons{
		pair{ Person{ "Izzie", "Fellows" }, 11 },
		pair{ Person{ "Eshaan", "Cooper" }, 15 },
		pair{ Person{ "Rick", "Crouch" }, 48 },
		pair{ Person{ "Faye", "Pittman" }, 35 },
		pair{ Person{ "Jude", "Bone" }, 69 },
		pair{ Person{ "Ella-Louise", "Byers" }, 60 },
		pair{ Person{ "Jad", "Lott" }, 75 },
		pair{ Person{ "Teddie", "Love" }, 24 },
		pair{ Person{ "Niko", "Silva" }, 16 },
		pair{ Person{ "Bryan", "Melendez" }, 42 },
	};

	{
		auto fourPersons{ views::common( // Convert the resulting range to a common range.
			persons
			| views::keys   // Only interested in the first element of each pair, the keys.
			| views::take(4)) };
		myCopy(begin(fourPersons), end(fourPersons), ostream_iterator<Person> { cout, "\n" });
	}

	println("");

	{
		// When using println(), there's no need to convert the resulting range to a common range.
		auto fourPersons{ persons
			| views::keys   // Only interested in the first element of each pair, the keys.
			| views::take(4)
			| views::transform([](const auto& person) { return person.getLastName(); }) };
		println("{:n:}", fourPersons);
	}
}
