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
	dataMap[1] = Data{ 4 };
	dataMap[1] = Data{ 6 };
	dataMap[1].setValue(100);

	auto it{ dataMap.find(1) };
	if (it != end(dataMap)) {
		it->second.setValue(100);
	}

	dataMap.at(1).setValue(200);
}
