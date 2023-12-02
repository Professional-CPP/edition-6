export module array;

import std;

export template <typename T>
class Array
{
public:
	// Creates an array with a default size that will grow as needed.
	Array();
	virtual ~Array();

	// Disallow copy constructor and copy assignment.
	Array& operator=(const Array& rhs) = delete;
	Array(const Array& src) = delete;

	// Move constructor and move assignment operator.
	Array(Array&& src) noexcept;
	Array& operator=(Array&& rhs) noexcept;

	T& operator[](std::size_t x);
	const T& operator[](std::size_t x) const;

	// Returns the value at index x. Throws an exception of type
	// out_of_range if index x does not exist in the array.
	const T& getElementAt(std::size_t x) const;

	// Sets the value at index x. If index x is out of range,
	// allocates more space to make it in range.
	void setElementAt(std::size_t x, const T& value);

	// Returns the number of elements in the array.
	std::size_t getSize() const noexcept;

private:
	static constexpr std::size_t AllocSize{ 4 };
	void resize(std::size_t newSize);
	T* m_elements{ nullptr };
	std::size_t m_size{ 0 };
};

template <typename T>
Array<T>::Array()
{
	m_elements = new T[AllocSize] {}; // Elements are zero-initialized!
	m_size = AllocSize;
}

template <typename T>
Array<T>::~Array()
{
	delete[] m_elements;
	m_elements = nullptr;
	m_size = 0;
}

template <typename T>
Array<T>::Array(Array&& src) noexcept
	: m_elements{ std::exchange(src.m_elements, nullptr) }
	, m_size{ std::exchange(src.m_size, 0) }
{
}

template <typename T>
Array<T>& Array<T>::operator=(Array<T>&& rhs) noexcept
{
	if (this == &rhs) {
		return *this;
	}
	
	delete[] m_elements;
	m_elements = std::exchange(rhs.m_elements, nullptr);
	m_size = std::exchange(rhs.m_size, 0);

	return *this;
}

template <typename T>
void Array<T>::resize(std::size_t newSize)
{
	// Create new bigger array with zero-initialized elements.
	auto newArray{ std::make_unique<T[]>(newSize) };

	// The new size is always bigger than the old size (m_size).
	for (std::size_t i{ 0 }; i < m_size; ++i) {
		// Copy the elements from the old array to the new one.
		newArray[i] = m_elements[i];
	}

	// Delete the old array, and set the new array.
	delete[] m_elements;
	m_size = newSize;
	m_elements = newArray.release();
}

template <typename T>
T& Array<T>::operator[](std::size_t x)
{
	if (x >= m_size) {
		// Allocate AllocSize past the element the client wants.
		resize(x + AllocSize);
	}
	return m_elements[x];
}

template <typename T>
const T& Array<T>::operator[](std::size_t x) const
{
	if (x >= m_size) {
		throw std::out_of_range{ "" };
	}
	return m_elements[x];
}

/*
template <typename T>
const T& Array<T>::operator[](std::size_t x) const
{
	if (x >= m_size) {
		static T nullValue{ T{} };
		return nullValue;
	}
	return m_elements[x];
}
*/

template <typename T>
const T& Array<T>::getElementAt(std::size_t x) const
{
	if (x >= m_size) {
		throw std::out_of_range{ "" };
	}
	return m_elements[x];
}

template <typename T>
void Array<T>::setElementAt(std::size_t x, const T& val)
{
	if (x >= m_size) {
		// Allocate AllocSize past the element the client wants.
		resize(x + AllocSize);
	}
	m_elements[x] = val;
}

template <typename T> std::size_t Array<T>::getSize() const noexcept
{
	return m_size;
}
