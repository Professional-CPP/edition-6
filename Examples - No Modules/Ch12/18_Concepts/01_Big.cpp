template <typename T>
concept Big = sizeof(T) > 4;

static_assert(!Big<char>);
static_assert(!Big<short>);
static_assert(Big<long double>);

int main()
{
}