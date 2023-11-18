import std;

using namespace std;

class BigData {};

class BigDataProcessor
{
public:
	explicit BigDataProcessor(unique_ptr<BigData> data) : m_data{ move(data) } {}
	void operator()() const { println("Processing BigData instance..."); }
private:
	unique_ptr<BigData> m_data;
};

int main()
{
	auto data{ make_unique<BigData>() };
	const move_only_function<void() const> processor{ BigDataProcessor{ move(data) } };
	processor();
}
