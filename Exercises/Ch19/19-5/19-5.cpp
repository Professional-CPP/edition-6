import std;

using namespace std;

class Processor
{
public:
	using Callback = function<int(int)>;

	explicit Processor(Callback callback)
		: m_callback{ move(callback) }
	{
	}

	int operator()(int value) const
	{
		return m_callback(value);
	}

private:
	Callback m_callback;
};


int square(int value) { return value * value; }
int cube(int value) { return value * value * value; }


int main()
{
	{
		Processor processor{ square };
		println("{}", processor(2));
	}

	{
		Processor processor{ cube };
		println("{}", processor(2));
	}
}
