import std;

using namespace std;

enum class PieceType
{
	King = 1,
	Queen,
	Rook = 10,
	Pawn
};

int main()
{
	{
		PieceType piece{ PieceType::King };

		auto underlyingValue{ to_underlying(piece) };
	}

	{
		using enum PieceType;
		PieceType piece{ King };
	}

	{
		using PieceType::King;
		PieceType piece{ King };
		piece = PieceType::Queen;
	}
}
