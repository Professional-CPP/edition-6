#pragma once

#include <string>
#include <string_view>

// Definition of a logger interface.
class ILogger
{
public:
	virtual ~ILogger() = default;  // Always a virtual destructor!

	enum class LogLevel {
		Debug,
		Info,
		Error
	};

	// Logs a single message at the given log level.
	virtual void log(LogLevel level, const std::string& message) = 0;
};


// Concrete implementation of ILogger.
class Logger : public ILogger
{
public:
	Logger();

	void log(LogLevel level, const std::string& message) override;

private:
	// Converts a log level to a human readable string.
	std::string_view getLogLevelString(LogLevel level) const;
};



// Adapted logger interface.
class IAdaptedLogger
{
public:
	virtual ~IAdaptedLogger() = default;  // Always a virtual destructor!
	// Logs a single message with Info as log level.
	virtual void log(std::string_view message) = 0;
};



// Implementation of adapted logger.
class AdaptedLogger : public IAdaptedLogger
{
public:
	AdaptedLogger();
	void log(std::string_view message) override;

private:
	Logger m_logger;
};
