import std;

using namespace std;

template <int i>
class Loop
{
public:
	template <typename FuncType>
	static void run(FuncType func) {
		Loop<i - 1>::run(func);
		func(i);
	}
};

template <>
class Loop<0>
{
public:
	template <typename FuncType>
	static void run(FuncType /* func */) { }
};

void doWork(int i)
{
	println("doWork({})", i);
}

int main()
{
	Loop<3>::run(doWork);
}
