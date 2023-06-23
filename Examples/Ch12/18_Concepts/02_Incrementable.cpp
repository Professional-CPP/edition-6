import std;

using namespace std;

template <typename T>
concept Incrementable = requires(T x) { x++; ++x; };

template <typename T>
concept Decrementable = requires(T x) { x--; --x; };

//template <typename T> requires Incrementable<T>
//void process(const T& t)
//{}

//template <typename T> requires convertible_to<T, bool>
//void process(const T& t)
//{}

//template <typename T> requires requires(T x) { x++; ++x; }
//void process(const T& t)
//{}

//template <typename T> requires (sizeof(T) == 4)
//void process(const T& t)
//{}

//template <typename T> requires Incrementable<T>&& Decrementable<T>
//void process(const T& t)
//{}

//template <typename T> requires is_arithmetic_v<T>
//void process(const T& t)
//{}

//template <typename T>
//void process(const T& t) requires Incrementable<T>
//{}

//template <convertible_to<bool> T>
//void process(const T& t)
//{}

//template <Incrementable T>
//void process(const T& t)
//{}

void process(const Incrementable auto& t)
{}

int main()
{
	process(123);
}