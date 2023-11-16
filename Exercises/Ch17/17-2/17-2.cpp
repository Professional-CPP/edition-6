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

template <input_iterator InputIter>
auto sum(InputIter begin, InputIter end)
{
	auto sum{ *begin };
	for (auto iter{ ++begin }; iter != end; ++iter) {
		sum += *iter;
	}
	return sum;
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

	auto filteredAges{ views::common( // Convert the resulting range to a common range.
		persons
		| views::values   // Only interested in the second element of each pair, the values.
		| views::filter([](const auto& age) { return age >= 12 && age <= 65; })) }; // Filter on age.
	
	auto count{ distance(begin(filteredAges), end(filteredAges)) }; // Cannot use ranges::size(filteredAges) here.
	
	auto average{ sum(begin(filteredAges), end(filteredAges)) /
		static_cast<double>(count) };
	
	println("Average: {}", average);
}
