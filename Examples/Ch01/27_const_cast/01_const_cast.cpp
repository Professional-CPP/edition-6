void thirdPartyLibraryFunction(char* str) {}

void f(const char* str)
{
	thirdPartyLibraryFunction(const_cast<char*>(str));
}

int main()
{
	f("Hello World");
}
