module;
#include <cassert>
#include <vector>
#include <memory>
#include <print>
#include <numeric>

export module object_pool;

// Provides an object pool that can be used with any class.
//
// acquireObject() returns an object from the list of free objects. If
// there are no more free objects, acquireObject() creates a new chunk
// of objects.
// The pool only grows: objects are never removed from the pool, until
// the pool is destroyed.
// acquireObject() returns an std::shared_ptr with a custom deleter that
// automatically puts the object back into the object pool when the
// shared_ptr is destroyed and its reference count reaches 0.
export
template <typename T, typename Allocator = std::allocator<T>>
class ObjectPool final
{
public:
	ObjectPool() = default;
	explicit ObjectPool(const Allocator& allocator);
	~ObjectPool();

	// Prevent move construction and move assignment.
	ObjectPool(ObjectPool&&) = delete;
	ObjectPool& operator=(ObjectPool&&) = delete;

	// Prevent copy construction and copy assignment.
	ObjectPool(const ObjectPool&) = delete;
	ObjectPool& operator=(const ObjectPool&) = delete;

	// Reserves and returns an object from the pool. Arguments can be
	// provided which are perfectly forwarded to a constructor of T.
	template <typename... Args>
	std::shared_ptr<T> acquireObject(Args&&... args);

private:
	// Creates a new block of uninitialized memory, big enough to hold
	// m_newChunkSize instances of T.
	void addChunk();
	// Contains chunks of memory in which instances of T will be created.
	// For each chunk, the pointer to its first object is stored.
	std::vector<T*> m_pool;
	// Contains pointers to all free instances of T that
	// are available in the pool.
	std::vector<T*> m_freeObjects;
	// The number of T instances that should fit in the first allocated chunk.
	static constexpr std::size_t ms_initialChunkSize{ 5 };
	// The number of T instances that should fit in a newly allocated chunk.
	// This value is doubled after each newly created chunk.
	std::size_t m_newChunkSize{ ms_initialChunkSize };
	// The allocator to use for allocating and deallocating chunks.
	Allocator m_allocator;
};

template <typename T, typename Allocator>
ObjectPool<T, Allocator>::ObjectPool(const Allocator& allocator)
	: m_allocator{ allocator }
{
}

template <typename T, typename Allocator>
ObjectPool<T, Allocator>::~ObjectPool()
{
	// Note: this implementation assumes that all objects handed out by this
	//       pool have been returned to the pool before the pool is destroyed.
	//       The following statement asserts if that is not the case.
	assert(m_freeObjects.size() == ms_initialChunkSize * (std::pow(2, m_pool.size()) - 1));

	// Deallocate all allocated memory.
	std::size_t chunkSize{ ms_initialChunkSize };
	for (auto* chunk : m_pool) {
		m_allocator.deallocate(chunk, chunkSize);
		chunkSize *= 2;
	}
	m_pool.clear();
}

template <typename T, typename Allocator>
template <typename... Args>
std::shared_ptr<T> ObjectPool<T, Allocator>::acquireObject(Args&&... args)
{
	// If there are no free objects, allocate a new chunk.
	if (m_freeObjects.empty()) { addChunk(); }

	// Get a free object.
	T* object{ m_freeObjects.back() };

	// Initialize, i.e. construct, an instance of T in an
	// uninitialized block of memory using placement new, and
	// perfectly forward any provided arguments to the constructor.
	::new(object) T{ std::forward<Args>(args)... };

	// Launder the object pointer.
	T* constructedObject{ std::launder(object) };

	// Remove the object from the list of free objects.
	m_freeObjects.pop_back();

	// Wrap the constructed object and return it.
	return std::shared_ptr<T>{constructedObject, [this](T* object) {
		// Destroy object.
		std::destroy_at(object);
		// Put the object back in the list of free objects.
		m_freeObjects.push_back(object);
	}};
}

template <typename T, typename Allocator>
void ObjectPool<T, Allocator>::addChunk()
{
	std::println("Allocating new chunk...");

	// Allocate a new chunk of uninitialized memory big enough to hold
	// m_newChunkSize instances of T, and add the chunk to the pool.
	// Care is taken that everything is cleaned up in the event of an exception.
	m_pool.push_back(nullptr);
	try {
		m_pool.back() = m_allocator.allocate(m_newChunkSize);
	} catch (...) {
		m_pool.pop_back();
		throw;
	}

	// Create pointers to each individual object in the new chunk
	// and store them in the list of free objects.
	auto oldFreeObjectsSize{ m_freeObjects.size() };
	m_freeObjects.resize(oldFreeObjectsSize + m_newChunkSize);
	std::iota(begin(m_freeObjects) + oldFreeObjectsSize, end(m_freeObjects), m_pool.back());

	// Double the chunk size for next time.
	m_newChunkSize *= 2;
}
