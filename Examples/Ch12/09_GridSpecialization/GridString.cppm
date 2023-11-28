export module grid:string;

import std;

// When the template specialization is used, the original template must be
// visible too.
import :main;

export
template <>
class Grid<const char*>
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

	std::optional<std::string>& at(std::size_t x, std::size_t y);
	const std::optional<std::string>& at(std::size_t x, std::size_t y) const;

	std::size_t getHeight() const { return m_height; }
	std::size_t getWidth() const { return m_width; }

	static constexpr std::size_t DefaultWidth{ 10 };
	static constexpr std::size_t DefaultHeight{ 10 };

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::vector<std::optional<std::string>> m_cells;
	std::size_t m_width { 0 }, m_height { 0 };
};

Grid<const char*>::Grid(std::size_t width, std::size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width * m_height);
}

void Grid<const char*>::verifyCoordinate(std::size_t x, std::size_t y) const
{
	if (x >= m_width) {
		throw std::out_of_range { std::format("x ({}) must be less than width ({}).", x, m_width) };
	}
	if (y >= m_height) {
		throw std::out_of_range { std::format("y ({}) must be less than height ({}).", y, m_height) };
	}
}

const std::optional<std::string>& Grid<const char*>::at(std::size_t x, std::size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x + y * m_width];
}

std::optional<std::string>& Grid<const char*>::at(std::size_t x, std::size_t y)
{
	return const_cast<std::optional<std::string>&>(std::as_const(*this).at(x, y));
}
