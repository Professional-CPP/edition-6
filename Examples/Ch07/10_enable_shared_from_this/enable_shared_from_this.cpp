import std;

using namespace std;

class Foo : public enable_shared_from_this<Foo>
{
public:
	shared_ptr<Foo> getPointer() {
		return shared_from_this();
	}
};

int main()
{
	auto ptr1{ make_shared<Foo>() };
	auto ptr2{ ptr1->getPointer() };
}
