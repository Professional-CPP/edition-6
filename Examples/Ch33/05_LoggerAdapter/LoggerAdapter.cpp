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
	case LogLevel::Debug: return "DEBUG";
	case LogLevel::Info: return "INFO";
	case LogLevel::Error: return "ERROR";
	}
	throw runtime_error{ "Invalid log level." };
}




AdaptedLogger::AdaptedLogger()
{
	println("AdaptedLogger constructor");
}

void AdaptedLogger::log(string_view message)
{
	m_logger.log(Logger::LogLevel::Info, string{ message });
}
