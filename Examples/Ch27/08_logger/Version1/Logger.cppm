export module logger;

import std;

export
class Logger
{
public:
	// Starts a background thread writing log entries to a file.
	Logger();
	// Prevent copy construction and assignment.
	Logger(const Logger&) = delete;
	Logger& operator=(const Logger&) = delete;
	// Add log entry to the queue.
	void log(std::string entry);

private:
	// The function running in the background thread.
	void processEntries();
	// Helper member function to process a queue of entries.
	void processEntriesHelper(std::queue<std::string>& queue, std::ofstream& ofs) const;
	// Mutex and condition variable to protect access to the queue.
	std::mutex m_mutex;
	std::condition_variable m_condVar;
	std::queue<std::string> m_queue;
	// The background thread.
	std::thread m_thread;
};
