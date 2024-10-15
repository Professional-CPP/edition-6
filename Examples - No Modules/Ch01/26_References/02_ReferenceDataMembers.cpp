class MyClass
{
public:
	MyClass(int& ref) : m_ref{ ref } { /* Body of constructor */ }

private:
	int& m_ref;
};

int main()
{
	int i{ 123 };
	MyClass m{ i };
}
