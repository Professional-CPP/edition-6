export module ilogger;

import std;

// Definition of a logger interface.
export class ILogger
{
public:
	// Virtual destructor.
	virtual ~ILogger() = default;

	// Enumeration for the different log levels.
	enum class LogLevel {
		Error,
		Info,
		Debug
	};

	// Sets the log level.
	virtual void setLogLevel(LogLevel level) = 0;

	// Logs a single message at the given log level.
	virtual void log(std::string_view message, LogLevel logLevel) = 0;
};
