export module simple_wrapper;

import std;

export template <typename T> requires std::floating_point<T> || std::integral<T>
class SimpleWrapper
{
public:
	SimpleWrapper(T& object) : m_object{ object } { }
	T& get() { return m_object; }

private:
	T& m_object;
};
