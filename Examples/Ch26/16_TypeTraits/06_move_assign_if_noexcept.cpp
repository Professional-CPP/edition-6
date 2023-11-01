import std;

using namespace std;

template <typename T>
constexpr conditional_t<is_nothrow_move_assignable_v<T>, T&&, const T&>
move_assign_if_noexcept(T& t) noexcept
{
	return std::move(t);
}

class MoveAssignable
{
public:
	MoveAssignable& operator=(const MoveAssignable&)
	{
		println("copy assign");
		return *this;
	}
	MoveAssignable& operator=(MoveAssignable&&)
	{
		println("move assign");
		return *this;
	}
};

class MoveAssignableNoexcept
{
public:
	MoveAssignableNoexcept& operator=(const MoveAssignableNoexcept&)
	{
		println("copy assign");
		return *this;
	}
	MoveAssignableNoexcept& operator=(MoveAssignableNoexcept&&) noexcept
	{
		println("move assign");
		return *this;
	}
};

int main()
{
	MoveAssignable a, b;
	a = move_assign_if_noexcept(b);
	MoveAssignableNoexcept c, d;
	c = move_assign_if_noexcept(d);
}
