export module grid;

import std;

export
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

	template <typename E>
	Grid(const Grid<E>& src);

	template <typename E>
	Grid& operator=(const Grid<E>& rhs);

	void swap(Grid& other) noexcept;

	//std::optional<T>& at(std::size_t x, std::size_t y);
	//const std::optional<T>& at(std::size_t x, std::size_t y) const;
	template <typename Self>
	auto&& at(this Self&& self, std::size_t x, std::size_t y);

	std::size_t getHeight() const { return m_height; }
	std::size_t getWidth() const { return m_width; }

	static constexpr std::size_t DefaultWidth{ 10 };
	static constexpr std::size_t DefaultHeight{ 10 };

private:
	void verifyCoordinate(std::size_t x, std::size_t y) const;

	std::vector<std::optional<T>> m_cells;
	std::size_t m_width { 0 }, m_height { 0 };
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

//template <typename T>
//const std::optional<T>& Grid<T>::at(std::size_t x, std::size_t y) const
//{
//	verifyCoordinate(x, y);
//	return m_cells[x + y * m_width];
//}
//
//template <typename T>
//std::optional<T>& Grid<T>::at(std::size_t x, std::size_t y)
//{
//	return const_cast<std::optional<T>&>(std::as_const(*this).at(x, y));
//}
template <typename T>
template <typename Self>
auto&& Grid<T>::at(this Self&& self, std::size_t x, std::size_t y)
{
	self.verifyCoordinate(x, y);
	return std::forward_like<Self>(self.m_cells[x + y * self.m_width]);
}

template <typename T>
template <typename E>
Grid<T>::Grid(const Grid<E>& src)
	: Grid{ src.getWidth(), src.getHeight() }
{
	// The ctor-initializer of this constructor delegates first to the
	// non-copy constructor to allocate the proper amount of memory.

	// The next step is to copy the data.
	for (std::size_t i{ 0 }; i < m_width; ++i) {
		for (std::size_t j{ 0 }; j < m_height; ++j) {
			at(i, j) = src.at(i, j);
		}
	}
}

template <typename T>
void Grid<T>::swap(Grid& other) noexcept
{
	std::swap(m_width, other.m_width);
	std::swap(m_height, other.m_height);
	std::swap(m_cells, other.m_cells);
}

template <typename T>
template <typename E>
Grid<T>& Grid<T>::operator=(const Grid<E>& rhs)
{
	// Copy-and-swap idiom
	Grid<T> temp{ rhs }; // Do all the work in a temporary instance.
	swap(temp); // Commit the work with only non-throwing operations.
	return *this;
}
