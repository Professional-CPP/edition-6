import logger;
import std;

using namespace std;

class Foo
{
public:
	explicit Foo(ILogger* logger) : m_logger{ logger }
	{
		if (m_logger == nullptr) {
			throw invalid_argument{ "ILogger cannot be null." };
		}
	}

	void doSomething()
	{
		m_logger->log("Hello strategy!", ILogger::LogLevel::Info);
	}

private:
	ILogger* m_logger;
};

int main()
{
	Logger concreteLogger{ "log.out" };
	concreteLogger.setLogLevel(ILogger::LogLevel::Debug);

	Foo f{ &concreteLogger };
	f.doSomething();
}
