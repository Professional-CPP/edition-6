import std;

using namespace std;

class TextHolder
{
public:
	explicit TextHolder(string text) : m_text{ move(text) } {}
	
	//const string& getText() const { return m_text; }
	
	const string& getText(this const TextHolder& self) { return self.m_text; }
	string&& getText(this TextHolder&& self) { return move(self.m_text); }

	TextHolder& operator=(this TextHolder& self, const string& rhs)
	{
		self.m_text = rhs;
		return self;
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
