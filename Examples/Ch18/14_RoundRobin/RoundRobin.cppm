export module round_robin;

import std;

// Class template RoundRobin
// Provides simple round-robin semantics for a list of elements.
export template <typename T>
class RoundRobin final
{
public:
	// Client can give a hint as to the number of expected elements for
	// increased efficiency.
	explicit RoundRobin(std::size_t numExpected = 0);

	// Prevent copy construction and copy assignment
	RoundRobin(const RoundRobin& src) = delete;
	RoundRobin& operator=(const RoundRobin& rhs) = delete;

	// Explicitly default a move constructor and move assignment operator
	RoundRobin(RoundRobin&& src) noexcept = default;
	RoundRobin& operator=(RoundRobin&& rhs) noexcept = default;

	// Appends element to the end of the list. May be called
	// between calls to getNext().
	void add(const T& element);

	// Removes the first (and only the first) element
	// in the list that is equal (with operator==) to element.
	// May be called between calls to getNext().
	void remove(const T& element);

	// Returns the next element in the list, starting with the first,
	// and cycling back to the first when the end of the list is
	// reached, taking into account elements that are added or removed.
	T& getNext();

private:
	std::vector<T> m_elements;
	typename std::vector<T>::iterator m_nextElement;
};

template <typename T>
RoundRobin<T>::RoundRobin(std::size_t numExpected)
{
	// If the client gave a guideline, reserve that much space.
	m_elements.reserve(numExpected);

	// Initialize m_nextElement even though it isn't used until
	// there's at least one element.
	m_nextElement = begin(m_elements);
}

// Always add the new element at the end.
template <typename T>
void RoundRobin<T>::add(const T& element)
{
	// Even though we add the element at the end, the vector could
	// reallocate and invalidate the m_nextElement iterator with
	// the push_back() call. Take advantage of the random-access
	// iterator features to save our spot.
	// Note: ptrdiff_t is a type capable of storing the difference
	//       between two random-access iterators.
	std::ptrdiff_t pos{ m_nextElement - begin(m_elements) };

	// Add the element.
	m_elements.push_back(element);
	
	// Reset our iterator to make sure it is valid.
	m_nextElement = begin(m_elements) + pos;
}

template <typename T>
void RoundRobin<T>::remove(const T& element)
{
	for (auto it{ begin(m_elements) }; it != end(m_elements); ++it) {
		if (*it == element) {
			// Removing an element invalidates the m_nextElement iterator
			// if it refers to an element past the point of the removal.
			// Take advantage of the random-access features of the iterator
			// to track the position of the current element after removal.
			std::ptrdiff_t newPos;

			if (m_nextElement == end(m_elements) - 1 &&
				m_nextElement == it) {
				// m_nextElement refers to the last element in the list,
				// and we are removing that last element, so wrap back to
				// the beginning.
				newPos = 0;
			} else if (m_nextElement <= it) {
				// Otherwise, if m_nextElement is before or at the one
				// we're removing, the new position is the same as before.
				newPos = m_nextElement - begin(m_elements);
			} else {
				// Otherwise, it's one less than before.
				newPos = m_nextElement - begin(m_elements) - 1;
			}

			// Erase the element (and ignore the return value).
			m_elements.erase(it);

			// Now reset our iterator to make sure it is valid.
			m_nextElement = begin(m_elements) + newPos;

			return;
		}
	}
}

template <typename T>
T& RoundRobin<T>::getNext()
{
	// First, make sure there are elements.
	if (m_elements.empty()) {
		throw std::out_of_range{ "No elements in the list" };
	}

	// Store the current element which we need to return.
	auto& toReturn{ *m_nextElement };

	// Increment the iterator modulo the number of elements.
	++m_nextElement;
	if (m_nextElement == end(m_elements)) {
		m_nextElement = begin(m_elements);
	}

	// Return a reference to the element.
	return toReturn;
}
