import std;

using namespace std;

template <typename T> requires integral<T>
void process(const T& t) { println("integral<T>"); }

template <typename T> requires (integral<T> && sizeof(T) == 4)
void process(const T& t) { println("integral<T> && sizeof(T) == 4"); }

int main()
{
	process(int{ 1 });
	process(short{ 2 });
}