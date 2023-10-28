import std;

using namespace std;

struct Foo { int m_array[123]; };
struct Bar { int m_int; };

int main()
{
	atomic<Foo> f;
	println("{} {}", is_trivially_copyable_v<Foo>, f.is_lock_free());

	atomic<Bar> b;
	println("{} {}", is_trivially_copyable_v<Bar>, b.is_lock_free());
}
