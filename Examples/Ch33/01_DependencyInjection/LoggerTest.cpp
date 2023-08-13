import logger;

using namespace std;

class Foo
{
public:
	explicit Foo(ILogger& logger) : m_logger{ logger } { }

	void doSomething()
	{
		m_logger.log("Hello dependency injection!", ILogger::LogLevel::Info);
	}

private:
	ILogger& m_logger;
};

int main()
{
	Logger concreteLogger{ "log.out" };
	concreteLogger.setLogLevel(ILogger::LogLevel::Debug);

	Foo f{ concreteLogger };
	f.doSomething();
}
