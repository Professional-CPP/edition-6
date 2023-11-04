export module simple_wrapper;

import std;

export template <typename T> requires (std::floating_point<T> || std::integral<T>)
class SimpleWrapper
{
public:
	explicit SimpleWrapper(T& object) : m_object{ object } { }
	T& get() const { return m_object; }

private:
	T& m_object;
};
