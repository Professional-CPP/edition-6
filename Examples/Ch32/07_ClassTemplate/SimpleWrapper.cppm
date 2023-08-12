export module simple_wrapper;

export template <typename T>
class SimpleWrapper
{
public:
	SimpleWrapper(T& object) : m_object{ object } { }
	T& get() { return m_object; }

private:
	T& m_object;
};
