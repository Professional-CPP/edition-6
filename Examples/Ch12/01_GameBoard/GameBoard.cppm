export module game_board;

import std;

export class GamePiece
{
public:
	virtual ~GamePiece() = default;
	virtual std::unique_ptr<GamePiece> clone() const = 0;
};

export class GameBoard
{
public:
	explicit GameBoard(std::size_t width = DefaultWidth, std::size_t height = DefaultHeight);
	GameBoard(const GameBoard& src);   // copy constructor
	virtual ~GameBoard() = default;    // virtual defaulted destructor
	GameBoard& operator=(const GameBoard& rhs); // assignment operator
	
	// Explicitly default a move constructor and move assignment operator.
	GameBoard(GameBoard&& src) = default;
	GameBoard& operator=(GameBoard&& src) = default;

	std::unique_ptr<GamePiece>& at(std::size_t x, std::size_t y);
	const std::unique_ptr<GamePiece>& at(std::size_t x, std::size_t y) const;

	std::size_t getHeight() const { return m_height; }
	std::size_t getWidth() const { return m_width; }

	static constexpr std::size_t DefaultWidth{ 10 };
	static constexpr std::size_t DefaultHeight{ 10 };

	void swap(GameBoard& other) noexcept;

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::vector<std::unique_ptr<GamePiece>> m_cells;
	std::size_t m_width { 0 }, m_height { 0 };
};

export void swap(GameBoard& first, GameBoard& second) noexcept;
