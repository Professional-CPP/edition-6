int func(int param1, [[maybe_unused]] int param2)
{
	return 42;
}

int main()
{
	int result{ func(1, 2) };
}