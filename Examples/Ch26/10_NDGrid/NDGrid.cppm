export module nd_grid; 

import std;

export
template <typename T, std::size_t N>
class NDGrid
{
public:
	explicit NDGrid(std::size_t size = DefaultSize) { resize(size); }
	virtual ~NDGrid() = default;

	NDGrid<T, N-1>& operator[](std::size_t x) { return m_elements[x]; }
	const NDGrid<T, N-1>& operator[](std::size_t x) const { return m_elements[x]; }

	void resize(std::size_t newSize)
	{
		m_elements.resize(newSize);

		// Resizing the vector calls the 0-argument constructor for
		// the NDGrid<T, N-1> elements, which constructs
		// it with the default size. Thus, we must explicitly call
		// resize() on each of the elements to recursively resize all
		// nested Grid elements.
		for (auto& element : m_elements) {
			element.resize(newSize);
		}
	}

	std::size_t getSize() const { return m_elements.size(); }

	static constexpr std::size_t DefaultSize{ 10 };

private:
	std::vector<NDGrid<T, N-1>> m_elements;
};

export
template <typename T>
class NDGrid<T, 1>
{
public:
	explicit NDGrid(std::size_t size = DefaultSize) { resize(size); }
	virtual ~NDGrid() = default;

	T& operator[](std::size_t x) { return m_elements[x]; }
	const T& operator[](std::size_t x) const { return m_elements[x]; }

	void resize(std::size_t newSize) { m_elements.resize(newSize); }
	std::size_t getSize() const { return m_elements.size(); }

	static constexpr std::size_t DefaultSize{ 10 };

private:
	std::vector<T> m_elements;
};
