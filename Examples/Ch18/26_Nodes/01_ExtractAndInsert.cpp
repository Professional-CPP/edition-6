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

	map<int, Data> dataMap2;
	
	//auto extractedNode{ dataMap.extract(1) };
	//dataMap2.insert(move(extractedNode));
	
	dataMap2.insert(dataMap.extract(1));
}
