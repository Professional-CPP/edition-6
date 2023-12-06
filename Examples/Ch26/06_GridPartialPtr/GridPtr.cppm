export module grid:pointers;

import :main;
import std;

export
template <typename U>
class Grid<U*>
{
public:
	explicit Grid(std::size_t width = DefaultWidth, std::size_t height = DefaultHeight);
	virtual ~Grid() = default;

	// Copy constructor and copy assignment operator.
	Grid(const Grid& src);
	Grid& operator=(const Grid& rhs);

	// Move constructor and move assignment operator.
	Grid(Grid&& src) noexcept;
	Grid& operator=(Grid&& rhs) noexcept;

	void swap(Grid& other) noexcept;

	std::unique_ptr<U>& at(std::size_t x, std::size_t y);
	const std::unique_ptr<U>& at(std::size_t x, std::size_t y) const;

	std::size_t getHeight() const { return m_height; }
	std::size_t getWidth() const { return m_width; }

	static constexpr std::size_t DefaultWidth{ 10 };
	static constexpr std::size_t DefaultHeight{ 10 };

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::vector<std::unique_ptr<U>> m_cells;
	std::size_t m_width { 0 }, m_height { 0 };
};

template <typename U>
Grid<U*>::Grid(std::size_t width, std::size_t height)
	: m_width{ width }
	, m_height{ height }
{
	m_cells.resize(m_width * m_height);
}

template <typename U>
void Grid<U*>::swap(Grid& other) noexcept
{
	using std::swap;

	swap(m_width, other.m_width);
	swap(m_height, other.m_height);
	swap(m_cells, other.m_cells);
}

template <typename U>
Grid<U*>::Grid(const Grid& src)
	: Grid { src.m_width, src.m_height }
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (std::size_t i{ 0 }; i < m_cells.size(); ++i) {
		// Make a deep copy of the element by using its copy constructor.
		if (src.m_cells[i] != nullptr) {
			m_cells[i] = std::make_unique<U>(*src.m_cells[i]);
		}
	}
}

template <typename U>
Grid<U*>& Grid<U*>::operator=(const Grid& rhs)
{
	// Use copy-and-swap idiom.
	auto copy{ rhs };    // Do all the work in a temporary instance
	swap(copy);          // Commit the work with only non-throwing operations
	return *this;
}

template <typename U>
Grid<U*>::Grid(Grid&& src) noexcept
{
	swap(src);
}

template <typename U>
Grid<U*>& Grid<U*>::operator=(Grid&& rhs) noexcept
{
	auto moved{ std::move(rhs) }; // Move rhs into moved (noexcept)
	swap(moved); // Commit the work with only non-throwing operations
	return *this;
}

template <typename U>
void Grid<U*>::verifyCoordinate(std::size_t x, std::size_t y) const
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

template <typename U>
const std::unique_ptr<U>& Grid<U*>::at(std::size_t x, std::size_t y) const
{
	verifyCoordinate(x, y);
	return m_cells[x + y * m_width];
}

template <typename U>
std::unique_ptr<U>& Grid<U*>::at(std::size_t x, std::size_t y)
{
	return const_cast<std::unique_ptr<U>&>(std::as_const(*this).at(x, y));
}
