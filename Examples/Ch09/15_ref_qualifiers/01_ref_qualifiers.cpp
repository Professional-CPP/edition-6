import std;

using namespace std;

class TextHolder
{
public:
	explicit TextHolder(string text) : m_text{ move(text) } {}
	
	//const string& getText() const { return m_text; }
	
	const string& getText() const & { return m_text; }
	string&& getText() && { return move(m_text); }

	TextHolder& operator=(const string& rhs) &
	{
		m_text = rhs;
		return *this;
	}

private:
	string m_text;
};

TextHolder makeTextHolder()
{
	return TextHolder{ "Hello World!" };
}

int main()
{
	TextHolder textHolder{ "Hello world!" };
	println("{}", textHolder.getText());
	println("{}", TextHolder{ "Hello world!" }.getText());

	// Pointless, object is a temporary.
	//makeTextHolder() = "Pointless!";

	// Ok
	auto text{ makeTextHolder() };
	text = "Ok";
}
