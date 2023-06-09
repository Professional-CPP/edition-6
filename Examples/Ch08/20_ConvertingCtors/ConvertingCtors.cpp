class MyClass
{
public:
	explicit MyClass(int) { }
	explicit MyClass(int, int) { }
};


void process(const MyClass& c) { }

int main()
{
	//process(1);
	//process({ 1 });
	//process({ 1, 2 });

	process(MyClass{ 1 });
	process(MyClass{ 1, 2 });
}
