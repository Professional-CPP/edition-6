import std;

using namespace std;

template <typename T1, typename T2>
enable_if_t<is_same_v<T1, T2>, bool>
checkType(const T1& t1, const T2& t2)
{
	println("'{}' and '{}' are the same types.", t1, t2);
	return true;
}

template <typename T1, typename T2>
enable_if_t<!is_same_v<T1, T2>, bool>
checkType(const T1& t1, const T2& t2)
{
	println("'{}' and '{}' are different types.", t1, t2);
	return false;
}

int main()
{
	checkType(1, 32);
	checkType(1, 3.01);
	checkType(3.01, "Test"s);
}
