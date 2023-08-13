import logger;
import std;

using namespace std;

int main()
{
	// Set the log filename before the first call to instance().
	Logger::setLogFilename("log.out");

	// Set log level to Debug.
	Logger::instance().setLogLevel(Logger::LogLevel::Debug);

	// Log some messages.
	Logger::instance().log("test message", Logger::LogLevel::Debug);

	// Set log level to Error.
	Logger::instance().setLogLevel(Logger::LogLevel::Error);

	// Now that the log level is set to Error, logging a Debug
	// message will be ignored.
	Logger::instance().log("A debug message", Logger::LogLevel::Debug);
}
