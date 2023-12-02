import std;

using namespace std;

enum class Figure { Diamond, Heart, Spade, Club };

class FigureEnumToString
{
public:
	static constexpr string_view operator[](Figure figure) noexcept
	{
		switch (figure) {
		case Figure::Diamond: return "Diamond";
		case Figure::Heart: return "Heart";
		case Figure::Spade: return "Spade";
		case Figure::Club: return "Club";
		}
	}
};

int main()
{
	Figure f{ Figure::Spade };
	FigureEnumToString converter;
	println("{}", converter[f]);
	println("{}", FigureEnumToString{}[f]);
}
