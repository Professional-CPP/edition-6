export module nd_grid; 

import std;

export
template <typename T, std::size_t N>
class NDGrid final
{
public:
	explicit NDGrid(std::size_t size = DefaultSize) { resize(size); }

	NDGrid<T, N-1>& operator[](std::size_t x) { return m_elements[x]; }
	const NDGrid<T, N-1>& operator[](std::size_t x) const { return m_elements[x]; }

	void resize(std::size_t newSize)
	{
		m_elements.resize(newSize, NDGrid<T, N-1> { newSize });
	}

	std::size_t getSize() const { return m_elements.size(); }

	static constexpr std::size_t DefaultSize{ 10 };

private:
	std::vector<NDGrid<T, N-1>> m_elements;
};

export
template <typename T>
class NDGrid<T, 1> final
{
public:
	explicit NDGrid(std::size_t size = DefaultSize) { resize(size); }

	T& operator[](std::size_t x) { return m_elements[x]; }
	const T& operator[](std::size_t x) const { return m_elements[x]; }

	void resize(std::size_t newSize) { m_elements.resize(newSize); }
	std::size_t getSize() const { return m_elements.size(); }

	static constexpr std::size_t DefaultSize{ 10 };

private:
	std::vector<T> m_elements;
};
