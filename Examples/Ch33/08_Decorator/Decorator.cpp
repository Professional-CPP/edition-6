import std;
using namespace std;

class IParagraph
{
public:
	virtual ~IParagraph() = default;  // Always a virtual destructor!
	virtual std::string getHTML() const = 0;
};

class Paragraph : public IParagraph
{
public:
	Paragraph(std::string text) : m_text{ std::move(text) } {}
	std::string getHTML() const override { return "<P>" + m_text + "</P>"; }

private:
	std::string m_text;
};

class BoldParagraph : public IParagraph
{
public:
	BoldParagraph(const IParagraph& paragraph) : m_wrapped{ paragraph } { }

	std::string getHTML() const override
	{
		return "<B>" + m_wrapped.getHTML() + "</B>";
	}

private:
	const IParagraph& m_wrapped;
};

class ItalicParagraph : public IParagraph
{
public:
	ItalicParagraph(const IParagraph& paragraph) : m_wrapped{ paragraph } { }

	std::string getHTML() const override
	{
		return "<I>" + m_wrapped.getHTML() + "</I>";
	}

private:
	const IParagraph& m_wrapped;
};



int main()
{
	Paragraph text{ "A party? For me? Thanks!" };

	// Bold
	println("{}", BoldParagraph{ text }.getHTML());

	// Bold and Italic
	println("{}", ItalicParagraph{ BoldParagraph{ text } }.getHTML());
}
