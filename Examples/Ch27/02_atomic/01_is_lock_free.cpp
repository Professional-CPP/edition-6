import std;

using namespace std;

class Foo { private: int m_array[123]; };
class Bar { private: int m_int; };

int main()
{
	atomic<Foo> f;
	println("{} {}", is_trivially_copyable_v<Foo>, f.is_lock_free());

	atomic<Bar> b;
	println("{} {}", is_trivially_copyable_v<Bar>, b.is_lock_free());
}
