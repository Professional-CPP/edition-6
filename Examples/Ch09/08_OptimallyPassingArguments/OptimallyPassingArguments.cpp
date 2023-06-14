import std;

using namespace std;

class DataHolder
{
public:
	//void setData(const vector<int>& data) { m_data = data; }
	//void setData(vector<int>&& data) { m_data = move(data); }
	void setData(vector<int> data) { m_data = move(data); }

private:
	vector<int> m_data;
};

int main()
{
	DataHolder wrapper;
	vector myData{ 11, 22, 33 };
	wrapper.setData(myData);

	wrapper.setData({ 22, 33, 44 });
}
