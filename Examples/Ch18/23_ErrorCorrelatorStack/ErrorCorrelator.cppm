export module error_correlator;

import std;

// Sample Error class with just a priority and a string error description.
export class Error final
{
public:
	explicit Error(int priority, std::string errorString)
		: m_priority{ priority }, m_errorString{ std::move(errorString) } { }
	int getPriority() const { return m_priority; }
	const std::string& getErrorString() const { return m_errorString; }
	// Compare Errors according to their priority.
	auto operator<=>(const Error& rhs) const { return getPriority() <=> rhs.getPriority(); }

private:
	int m_priority;
	std::string m_errorString;
};

// Stream insertion overload for Errors.
export std::ostream& operator<<(std::ostream& os, const Error& err)
{
	std::print(os, "{} (priority {})", err.getErrorString(), err.getPriority());
	return os;
}

// Simple ErrorCorrelator class that returns highest priority errors first.
export class ErrorCorrelator final
{
public:
	// Add an error to be correlated.
	void addError(const Error& error) { m_errors.push(error); }

	// Retrieve the next error to be processed.
	[[nodiscard]] Error getError()
	{
		// If there are no more errors, throw an exception.
		if (m_errors.empty()) {
			throw std::out_of_range{ "No more errors." };
		}
		// Save the top element.
		Error top{ m_errors.top() };
		// Remove the top element.
		m_errors.pop();
		// Return the saved element.
		return top;
	}
private:
	std::stack<Error> m_errors;
};
