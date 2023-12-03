import std;

using namespace std;

template <typename T>
class Pointer final
{
public:
	[[nodiscard]] explicit Pointer(T* data);
	~Pointer();

	// Prevent copy construction and copy assignment.
	Pointer(const Pointer& src) = delete;
	Pointer& operator=(const Pointer& rhs) = delete;

	// Allow move construction and move assignment.
	Pointer(Pointer&& src) noexcept;
	Pointer& operator=(Pointer&& rhs) noexcept;

	T& operator*() noexcept;
	const T& operator*() const noexcept;

	[[nodiscard]] T* release() noexcept;
	void reset(T* data = nullptr) noexcept;

private:
	T* m_data{ nullptr };
};

template <typename T>
Pointer<T>::Pointer(T* data) : m_data{ data }
{
}

template <typename T>
Pointer<T>::~Pointer()
{
	reset();
}

template <typename T>
Pointer<T>::Pointer(Pointer&& src) noexcept
	: m_data{ std::exchange(src.m_data, nullptr) }
{
}

template <typename T>
Pointer<T>& Pointer<T>::operator=(Pointer&& rhs) noexcept
{
	if (this != &rhs) {
		reset();
		m_data = std::exchange(rhs.m_data, nullptr);
	}
	return *this;
}

template <typename T>
T& Pointer<T>::operator*() noexcept
{
	return *m_data;
}

template <typename T>
const T& Pointer<T>::operator*() const noexcept
{
	return *m_data;
}

template <typename T>
T* Pointer<T>::release() noexcept
{
	return std::exchange(m_data, nullptr);
}

template <typename T>
void Pointer<T>::reset(T* data /*= nullptr*/) noexcept
{
	if (m_data) {
		delete m_data;
	}
	m_data = data;
}

int main()
{
	Pointer pointer{ new int{ 42 } };
	println("{}", *pointer);
	
	Pointer pointer2{ std::move(pointer) };
	println("{}", *pointer2);

	Pointer<int> pointer3{ nullptr };
	pointer3 = std::move(pointer2);
	println("{}", *pointer3);

	pointer3 = std::move(pointer3);
	println("{}", *pointer3);
}
