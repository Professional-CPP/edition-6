#pragma once

template <typename T>
class SimpleWrapper
{
public:
	explicit SimpleWrapper(T& object) : m_object{ object } { }
	T& get() const { return m_object; }

private:
	T& m_object;
};
