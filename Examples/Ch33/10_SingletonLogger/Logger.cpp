module logger;

import std;

using namespace std;

void Logger::setLogFilename(string logFilename)
{
	ms_logFilename = move(logFilename);
}

Logger& Logger::instance()
{
	static Logger instance; // Thread-safe static local variable.
	return instance;
}

Logger::Logger()
{
	m_outputStream.open(ms_logFilename, ios_base::app);
	if (!m_outputStream.good()) {
		throw runtime_error{ "Unable to initialize the Logger!" };
	}
	println(m_outputStream, "{}: Logger started.", chrono::system_clock::now());
}

Logger::~Logger()
{
	println(m_outputStream, "{}: Logger stopped.", chrono::system_clock::now());
}

void Logger::setLogLevel(LogLevel level)
{
	m_logLevel = level;
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

void Logger::log(string_view message, LogLevel logLevel)
{
	if (m_logLevel > logLevel) {
		return;
	}

	println(m_outputStream, "{}: [{}] {}", chrono::system_clock::now(),
		getLogLevelString(logLevel), message);
}
