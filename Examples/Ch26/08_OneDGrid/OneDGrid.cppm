export module oned_grid;

import std;

export
template <typename T>
class OneDGrid final
{
public:
	explicit OneDGrid(std::size_t size = DefaultSize) { resize(size); }

	T& operator[](std::size_t x) { return m_elements[x]; }
	const T& operator[](std::size_t x) const { return m_elements[x]; }

	void resize(std::size_t newSize) { m_elements.resize(newSize); }
	std::size_t getSize() const { return m_elements.size(); }

	static constexpr std::size_t DefaultSize{ 10 };

private:
	std::vector<T> m_elements;
};
