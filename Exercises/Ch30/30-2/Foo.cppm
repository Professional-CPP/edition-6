export module foo;

import std;

export class Foo
{
public:
	// Constructs a Foo. Throws invalid_argument if a >= b.
	explicit Foo(int a, int b) : m_a{ a }, m_b{ b }
	{
		if (a >= b) {
			throw std::invalid_argument{ "a should be less than b." };
		}
	}

	int getA() const { return m_a; }
	int getB() const { return m_b; }

private:
	int m_a{ 0 };
	int m_b{ 0 };
};
