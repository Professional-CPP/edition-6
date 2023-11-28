import std;

template <typename T>
class Grid
{
public:
	explicit Grid(std::size_t width = DefaultWidth, std::size_t height = DefaultHeight);
	virtual ~Grid() = default;

	// Explicitly default a copy constructor and copy assignment operator.
	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	// Explicitly default a move constructor and move assignment operator.
	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	std::optional<T>& at(std::size_t x, std::size_t y);
	const std::optional<T>& at(std::size_t x, std::size_t y) const;

	std::size_t getHeight() const { return m_height; }
	std::size_t getWidth() const { return m_width; }

	static constexpr std::size_t DefaultWidth{ 10 };
	static constexpr std::size_t DefaultHeight{ 10 };

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::vector<std::optional<T>> m_cells;
	std::size_t m_width{ 0 }, m_height{ 0 };
};

template <typename T>
Grid<T>::Grid(std::size_t width, std::size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width * m_height);
}

template <typename T>
void Grid<T>::verifyCoordinate(std::size_t x, std::size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range { std::format("x ({}) must be less than width ({}).", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range { std::format("y ({}) must be less than height ({}).", y, m_height) };
	}
}

template <typename T>
const std::optional<T>& Grid<T>::at(std::size_t x, std::size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x + y * m_width];
}

template <typename T>
std::optional<T>& Grid<T>::at(std::size_t x, std::size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}





class GamePiece
{
public:
	virtual ~GamePiece() = default;
};






template <std::derived_from<GamePiece> T>
class GameBoard : public Grid<T>
{
public:
	// Inherit constructors from Grid<T>.
	using Grid<T>::Grid;

	void move(std::size_t xSrc, std::size_t ySrc, std::size_t xDest, std::size_t yDest);
};


template <std::derived_from<GamePiece> T>
void GameBoard<T>::move(std::size_t xSrc, std::size_t ySrc, std::size_t xDest, std::size_t yDest)
{
	Grid<T>::at(xDest, yDest) = std::move(Grid<T>::at(xSrc, ySrc));
	Grid<T>::at(xSrc, ySrc).reset(); // Reset source cell
	// Or:
	// this->at(xDest, yDest) = std::move(this->at(xSrc, ySrc));
	// this->at(xSrc, ySrc).reset();
}





class ChessPiece : public GamePiece
{
};

int main()
{
	GameBoard<ChessPiece> chessBoard{ 8, 8 };

	ChessPiece pawn;
	chessBoard.at(0, 0) = pawn;
	chessBoard.move(0, 0, 0, 1);
}
