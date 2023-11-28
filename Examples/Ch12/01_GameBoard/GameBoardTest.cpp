import game_board;
import std;

class ChessPiece : public GamePiece
{
public:
	std::unique_ptr<GamePiece> clone() const override
	{
		// Call the copy constructor to copy this instance
		return std::make_unique<ChessPiece>(*this);
	}
};

void processGameBoard(const GameBoard& board)
{
	const std::unique_ptr<GamePiece>& pawn{ board.at(0, 0) };

	// Doesn't compile
	//board.at(1, 2) = std::make_unique<ChessPiece>();
}

int main()
{
	GameBoard chessBoard{ 8, 8 };
	auto pawn{ std::make_unique<ChessPiece>() };
	chessBoard.at(0, 0) = std::move(pawn);
	chessBoard.at(0, 1) = std::make_unique<ChessPiece>();
	chessBoard.at(0, 1) = nullptr;

	GameBoard board2;
	board2 = chessBoard;

	processGameBoard(board2);
}
