module memory_demo;

import std;

using namespace std;

void* MemoryDemo::operator new(size_t size)
{
	println("operator new");
	return ::operator new(size);
}

void MemoryDemo::operator delete(void* ptr) noexcept
{
	println("operator delete");
	::operator delete(ptr);
}

//void MemoryDemo::operator delete(void* ptr, size_t size) noexcept
//{
//	println("operator delete with size {}", size);
//	::operator delete(ptr, size);
//}

void* MemoryDemo::operator new[](size_t size)
{
	println("operator new[]");
	return ::operator new[](size);
}

void MemoryDemo::operator delete[](void* ptr) noexcept
{
	println("operator delete[]");
	::operator delete[](ptr);
}

void* MemoryDemo::operator new(size_t size, const nothrow_t&) noexcept
{
	println("operator new nothrow");
	return ::operator new(size, nothrow);
}

void MemoryDemo::operator delete(void* ptr, const nothrow_t&) noexcept
{
	println("operator delete nothrow");
	::operator delete(ptr, nothrow);
}

void* MemoryDemo::operator new[](size_t size, const nothrow_t&) noexcept
{
	println("operator new[] nothrow");
	return ::operator new[](size, nothrow);
}

void MemoryDemo::operator delete[](void* ptr, const nothrow_t&) noexcept
{
	println("operator delete[] nothrow");
	::operator delete[](ptr, nothrow);
}

void* MemoryDemo::operator new(size_t size, int extra)
{
	println("operator new with extra int: {}", extra);
	return ::operator new(size);
}

void MemoryDemo::operator delete(void* ptr, int extra) noexcept
{
	println("operator delete with extra int: {}", extra);
	return ::operator delete(ptr);
}
