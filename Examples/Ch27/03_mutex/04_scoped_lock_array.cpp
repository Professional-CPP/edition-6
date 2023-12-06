import std;

using namespace std;

// Helper function to create the actual scoped_lock instance.
template<size_t N, size_t... Is>
auto make_scoped_lock(array<mutex, N>& mutexes, index_sequence<Is...>)
{
	return scoped_lock{ mutexes[Is]... };
}

// Helper function to make it easy to use.
template<size_t N>
auto make_scoped_lock(array<mutex, N>& mutexes)
{
	return make_scoped_lock(mutexes, make_index_sequence<N>{});
}

int main()
{
	array<std::mutex, 4> mutexes;

	auto lockAll{ make_scoped_lock(mutexes) };
}
