import std;

// using automatic function return type deduction
template<typename T1, typename T2>
auto add(const T1& t1, const T2& t2)
{
	return t1 + t2;
}

// using decltype(auto)
//template<typename T1, typename T2>
//decltype(auto) add(const T1& t1, const T2& t2)
//{
//	return t1 + t2;
//}

// Using the alternative function syntax
//template<typename T1, typename T2>
//auto add(const T1& t1, const T2& t2) -> decltype(t1 + t2)
//{
//	return t1 + t2;
//}

// Using std::declval<>()
//template<typename T1, typename T2>
//decltype(std::declval<T1>() + std::declval<T2>()) add(const T1& t1, const T2& t2)
//{
//	return t1 + t2;
//}

int main()
{
	std::println("{}", add(2, 4));
}
