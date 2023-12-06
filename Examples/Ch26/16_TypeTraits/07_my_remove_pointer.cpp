import std;
using namespace std;

// my_remove_pointer class template.
template <typename T>
struct my_remove_pointer {
	using type = T;
};

// Partial specialization for pointer types.
template <typename T>
struct my_remove_pointer<T*> {
	using type = T;
};

// Partial specialization for const pointer types.
template <typename T>
struct my_remove_pointer<T* const> {
	using type = T;
};

// Alias template for ease of use.
template <typename T>
using my_remove_pointer_t = typename my_remove_pointer<T>::type;

int main()
{
	println("{}", is_same_v<string, my_remove_pointer_t<string*>>);
}