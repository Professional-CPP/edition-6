module logger;

import std;

using namespace std;

Logger::Logger()
{
	println("Logger constructor");
}

void Logger::log(LogLevel level, const string& message)
{
	println("{}: [{}] {}", chrono::system_clock::now(),
		getLogLevelString(level), message);
}

string_view Logger::getLogLevelString(LogLevel level) const
{
	switch (level) {
	case LogLevel::Error: return "ERROR";
	case LogLevel::Info: return "INFO";
	case LogLevel::Debug: return "DEBUG";
	}
	throw runtime_error{ "Invalid log level." };
}




NewLoggerAdapter::NewLoggerAdapter()
{
	println("NewLoggerAdapter constructor");
}

void NewLoggerAdapter::log(string_view message)
{
	m_logger.log(Logger::LogLevel::Info, message.data());
}
