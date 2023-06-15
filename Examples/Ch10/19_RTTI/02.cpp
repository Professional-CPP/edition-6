import std;

using namespace std;

class Loggable
{
public:
	virtual ~Loggable() = default;
	virtual string getLogMessage() const = 0;
};

class Foo : public Loggable
{
public:
	string getLogMessage() const override { return "Hello logger."; }
};

void logObject(const Loggable& loggableObject)
{
	print("{}: ", typeid(loggableObject).name());
	println("{}", loggableObject.getLogMessage());
}

int main()
{
	Foo f;
	logObject(f);
}
