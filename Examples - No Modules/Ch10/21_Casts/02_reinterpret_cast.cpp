class X {};
class Y {};

int main()
{
	X x;
	Y y;

	X* xp{ &x };
	Y* yp{ &y };

	// Need reinterpret_cast for pointer conversion from unrelated classes
	// static_cast doesn't work.
	xp = reinterpret_cast<X*>(yp);

	// No cast required for conversion from pointer to void*
	void* p{ xp };
	// static_cast is enough for pointer conversion from void*
	xp = static_cast<X*>(p);

	// Need reinterpret_cast for reference conversion from unrelated classes
	// static_cast doesn't work.
	X& xr{ x };
	Y& yr{ reinterpret_cast<Y&>(x) };
}
