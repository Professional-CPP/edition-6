export module grid;

import std;

export
template <typename T, std::size_t WIDTH = 10, std::size_t HEIGHT = 10>
class Grid
{
public:
	Grid() = default;
	virtual ~Grid() = default;

	// Explicitly default a copy constructor and copy assignment operator.
	Grid(const Grid& src) = default;
	Grid& operator=(const Grid& rhs) = default;

	// Explicitly default a move constructor and move assignment operator.
	Grid(Grid&& src) = default;
	Grid& operator=(Grid&& rhs) = default;

	template <typename E, std::size_t WIDTH2, std::size_t HEIGHT2>
	Grid(const Grid<E, WIDTH2, HEIGHT2>& src);

	template <typename E, std::size_t WIDTH2, std::size_t HEIGHT2>
	Grid& operator=(const Grid<E, WIDTH2, HEIGHT2>& rhs);

	void swap(Grid& other) noexcept;

	std::optional<T>& at(std::size_t x, std::size_t y);
	const std::optional<T>& at(std::size_t x, std::size_t y) const;

	std::size_t getHeight() const { return HEIGHT; }
	std::size_t getWidth() const { return WIDTH; }

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::optional<T> m_cells[WIDTH][HEIGHT];
};

template <typename T, std::size_t WIDTH, std::size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::verifyCoordinate(std::size_t x, std::size_t y) const
{
	if (x >= WIDTH) {
		throw std::out_of_range { std::format("x ({}) must be less than width ({}).", x, WIDTH) };
	}
	if (y >= HEIGHT) {
		throw std::out_of_range { std::format("y ({}) must be less than height ({}).", y, HEIGHT) };
	}
}

template <typename T, std::size_t WIDTH, std::size_t HEIGHT>
const std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(std::size_t x, std::size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x][y];
}

template <typename T, std::size_t WIDTH, std::size_t HEIGHT>
std::optional<T>& Grid<T, WIDTH, HEIGHT>::at(std::size_t x, std::size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}

template <typename T, std::size_t WIDTH, std::size_t HEIGHT>
template <typename E, std::size_t WIDTH2, std::size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>::Grid(const Grid<E, WIDTH2, HEIGHT2>& src)
{
	for (std::size_t i{ 0 }; i < WIDTH; ++i) {
		for (std::size_t j{ 0 }; j < HEIGHT; ++j) {
			if (i < WIDTH2 && j < HEIGHT2) {
				m_cells[i][j] = src.at(i, j);
			}
			else {
				m_cells[i][j].reset();
			}
		}
	}
}

template <typename T, std::size_t WIDTH, std::size_t HEIGHT>
void Grid<T, WIDTH, HEIGHT>::swap(Grid& other) noexcept
{
	std::swap(m_cells, other.m_cells);
}

template <typename T, std::size_t WIDTH, std::size_t HEIGHT>
template <typename E, std::size_t WIDTH2, std::size_t HEIGHT2>
Grid<T, WIDTH, HEIGHT>& Grid<T, WIDTH, HEIGHT>::operator=(
	const Grid<E, WIDTH2, HEIGHT2>& rhs)
{
	// Copy-and-swap idiom
	Grid<T, WIDTH, HEIGHT> temp{ rhs }; // Do all the work in a temporary instance.
	swap(temp); // Commit the work with only non-throwing operations.
	return *this;
}
