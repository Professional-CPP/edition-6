// An immediate function.
consteval int f(int i)
{
	return i;
}

// A constexpr function.
constexpr int g(int i)
{
	if consteval { return f(i); }
	else { return 42; }
}


int main()
{
	g(21);
}
