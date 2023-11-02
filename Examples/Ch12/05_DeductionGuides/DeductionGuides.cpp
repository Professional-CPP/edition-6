import std;

using namespace std;

template <typename T>
class SpreadsheetCell
{
public:
	explicit SpreadsheetCell(T t) : m_content{ move(t) } { }
	const T& getContent() const { return m_content; }
private:
	T m_content;
};

SpreadsheetCell(const char*) -> SpreadsheetCell<std::string>;

int main()
{
	string myString{ "Hello World!" };
	SpreadsheetCell cell{ myString };

	SpreadsheetCell cell2{ "test" };
}
