import std;

using namespace std;

class MyClass
{
public:
	MyClass() = default;
	MyClass(const MyClass& src) = default;
	explicit MyClass(string str) : m_str{ move(str) } {}
	virtual ~MyClass() = default;
	
	// Move assignment operator
	MyClass& operator=(MyClass&& rhs) noexcept {
		if (this == &rhs) { return *this; }
		m_str = move(rhs.m_str);
		println("Move operator= (m_str={})", m_str);
		return *this;
	}
	
	void setString(string str) { m_str = move(str); }
	const string& getString() const { return m_str; }

private:
	string m_str;
};

int main()
{
	vector<MyClass> vecSrc{ MyClass { "a" }, MyClass { "b" }, MyClass { "c" } };
	vector<MyClass> vecDst(vecSrc.size());
	move(begin(vecSrc), end(vecSrc), begin(vecDst));
	for (const auto& c : vecDst) { print("{} ", c.getString()); }
}
