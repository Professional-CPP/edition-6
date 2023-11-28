import std;

using namespace std;

class Muffin final
{
public:
	const string& getDescription() const { return m_description; }
	void setDescription(string description) { m_description = std::move(description); }

	int getSize() const { return m_size; }
	void setSize(int size) { m_size = size; }

	bool hasChocolateChips() const { return m_hasChocolateChips; }
	void setHasChocolateChips(bool hasChips) { m_hasChocolateChips = hasChips; }

private:
	string m_description;
	int m_size{ 0 };
	bool m_hasChocolateChips{ false };
};

template <>
class std::formatter<Muffin>
{
public:
	constexpr auto parse(auto& context)
	{
		return begin(context);
	}

	auto format(const Muffin& muffin, auto& ctx) const
	{
		ctx.advance_to(format_to(ctx.out(), "{}, size is {}, {}",
			muffin.getDescription(), muffin.getSize(),
			(muffin.hasChocolateChips() ? "has chips" : "no chips")));
		return ctx.out();
	}
};

Muffin createMuffin(istringstream& inStream);

int main()
{
	println("First, let's create a muffin in code and output it.");

	Muffin myMuffin;
	myMuffin.setDescription("Giant Blueberry Muffin");
	myMuffin.setSize(42);
	myMuffin.setHasChocolateChips(false);

	println("The muffin is a {} -- yummy!", myMuffin);


	println("Now we'll create a muffin from a string stream.");

	istringstream instream{ "\"Raspberry Muffin\" 12 true" };
	Muffin muffin2{ createMuffin(instream) };
	println("The parsed muffin is a {}.", muffin2);
}

Muffin createMuffin(istringstream& stream)
{
	Muffin muffin;
	// Assume data is properly formatted:
	// "Description" size chips

	string description;
	int size;
	bool hasChips;

	// Read all three values. Note that chips is represented
	// by the strings "true" and "false".
	stream >> quoted(description) >> size >> boolalpha >> hasChips;
	if (stream) { // Reading was successful.
		muffin.setSize(size);
		muffin.setDescription(description);
		muffin.setHasChocolateChips(hasChips);
	}

	return muffin;
}
