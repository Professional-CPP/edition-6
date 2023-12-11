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

	println("There are {} elements with key 1.", dataMap.count(1));
	dataMap.erase(1);
	println("There are {} elements with key 1.", dataMap.count(1));
}
