import std;

using namespace std;

class Data final
{
public:
	explicit Data(int value = 0) : m_value{ value } { }
	int getValue() const { return m_value; }
	void setValue(int value) { m_value = value; }

private:
	int m_value;
};

int main()
{
	map<int, Data> dataMap;

	auto ret{ dataMap.insert({ 1, Data{ 4 } }) };   // Using an initializer_list
	if (ret.second) {
		println("Insert succeeded!");
	} else {
		println("Insert failed!");
	}

	ret = dataMap.insert(make_pair(1, Data{ 6 })); // Using a pair object
	if (ret.second) {
		println("Insert succeeded!");
	} else {
		println("Insert failed!");
	}

	// Using if statement initializers
	if (auto result{ dataMap.insert({ 1, Data{ 4 } }) }; result.second) {
		println("Insert succeeded!");
	} else {
		println("Insert failed!");
	}

	// Using if statement initializers and structured bindings
	if (auto [iter, success]{ dataMap.insert({ 1, Data{ 4 } }) }; success) {
		println("Insert succeeded!");
	} else {
		println("Insert failed!");
	}

	ret = dataMap.insert_or_assign(1, Data{ 7 });
	if (ret.second) {
		println("Inserted.");
	} else {
		println("Overwritten.");
	}

	// C++23 insert_range()
	vector<pair<int, Data>> moreData{
		{ 2, Data{ 22 } },
		{ 3, Data{ 33 } },
		{ 4, Data{ 44 } }
	};
	dataMap.insert_range(moreData);
}
