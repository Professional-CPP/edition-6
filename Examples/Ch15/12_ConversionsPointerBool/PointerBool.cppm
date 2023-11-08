export module pointer;

import std;

export template <typename T>
class Pointer
{
public:
	explicit Pointer(T* ptr) : m_ptr{ ptr } {}

	virtual ~Pointer()
	{
		reset();
	}

	// Disallow copy constructor and copy assignment.
	Pointer(const Pointer& src) = delete;
	Pointer& operator=(const Pointer& rhs) = delete;

	// Allow move construction.
	Pointer(Pointer&& src) noexcept : m_ptr{ std::exchange(src.m_ptr, nullptr) }
	{
	}

	// Allow move assignment.
	Pointer& operator=(Pointer&& rhs) noexcept
	{
		if (this != &rhs) {
			reset();
			m_ptr = std::exchange(rhs.m_ptr, nullptr);
		}
		return *this;
	}

	T& operator*() { return *m_ptr; }
	const T& operator*() const { return *m_ptr; }

	T* operator->() { return m_ptr; }
	const T* operator->() const { return m_ptr; }

	operator bool() const { return m_ptr != nullptr; }

	//template <typename T>
	//friend bool operator!=(const Pointer<T>& lhs, std::nullptr_t rhs);

private:
	void reset()
	{
		delete m_ptr;
		m_ptr = nullptr;
	}
	T* m_ptr{ nullptr };
};

//export template <typename T>
//bool operator!=(const Pointer<T>& lhs, std::nullptr_t rhs)
//{
//	return lhs.m_ptr != rhs;
//}
