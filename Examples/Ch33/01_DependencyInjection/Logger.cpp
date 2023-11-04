module logger;

import std;

using namespace std;

Logger::Logger(const string& logFilename)
{
	m_outputStream.open(logFilename, ios_base::app);
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
	case LogLevel::Error: return "ERROR";
	case LogLevel::Info: return "INFO";
	case LogLevel::Debug: return "DEBUG";
	}
	throw runtime_error{ "Invalid log level." };
}

void Logger::log(string_view message, LogLevel logLevel)
{
	if (m_logLevel < logLevel) {
		return;
	}

	println(m_outputStream, "{}: [{}] {}", chrono::system_clock::now(),
		getLogLevelString(logLevel), message);
}
