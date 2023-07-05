export module pointer;

export template <typename T>
class Pointer
{
public:
	Pointer(T* ptr) : m_ptr{ ptr } {}

	virtual ~Pointer()
	{
		delete m_ptr;
		m_ptr = nullptr;
	}

	// Prevent assignment and pass by value.
	Pointer(const Pointer& src) = delete;
	Pointer& operator=(const Pointer& rhs) = delete;

	T& operator*() { return *m_ptr; }
	const T& operator*() const { return *m_ptr; }

	T* operator->() { return m_ptr; }
	const T* operator->() const { return m_ptr; }

private:
	T* m_ptr{ nullptr };
};
