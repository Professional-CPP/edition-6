export module grid;

import std;

export
template <typename T,
	template <typename E, typename Allocator = std::allocator<E>> class Container = std::vector>
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

	Container<std::optional<T>> m_cells;
	std::size_t m_width { 0 }, m_height { 0 };
};

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
Grid<T, Container>::Grid(std::size_t width, std::size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width * m_height);
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
void Grid<T, Container>::verifyCoordinate(std::size_t x, std::size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range{
			std::format("x ({}) must be less than width ({}).", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range{
			std::format("y ({}) must be less than height ({}).", y, m_height) };
	}
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
const std::optional<T>& Grid<T, Container>::at(std::size_t x, std::size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x + y * m_width];
}

template <typename T, template <typename E, typename Allocator = std::allocator<E>> class Container>
std::optional<T>& Grid<T, Container>::at(std::size_t x, std::size_t y)
{
	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
}
