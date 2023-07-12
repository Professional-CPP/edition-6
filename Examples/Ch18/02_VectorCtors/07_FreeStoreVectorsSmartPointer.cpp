import std;

using namespace std;

class Element
{
public:
	Element() {}
	virtual ~Element() = default;
};

int main()
{
	auto elementVector{ make_unique<vector<Element>>(10) };
}
