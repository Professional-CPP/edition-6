module logger;

import std;

using namespace std;

Logger::Logger()
{
	// Start background thread.
	m_thread = thread{ &Logger::processEntries, this };
}

void Logger::log(string entry)
{
	// Lock mutex and add entry to the queue.
	lock_guard lock{ m_mutex };
	m_queue.push(move(entry));

	// Notify condition variable to wake up thread.
	m_condVar.notify_all();
}

void Logger::processEntries()
{
	// Open log file.
	ofstream logFile{ "log.txt" };
	if (logFile.fail()) {
		println(cerr, "Failed to open logfile.");
		return;
	}

	unique_lock lock{ m_mutex }; // Acquire a lock on m_mutex.
	while (true) { // Start processing loop.
		// Wait for a notification.
		m_condVar.wait(lock);

		// Condition variable is notified, so something might be in the queue.

		// While we still have the lock, swap the contents of the current queue
		// with an empty local queue on the stack.
		queue<string> localQueue;
		localQueue.swap(m_queue);

		// Now that all entries have been moved from the current queue to the
		// local queue, we can release the lock so other threads are not blocked
		// while we process the entries.
		lock.unlock();

		// Process the entries in the local queue on the stack. This happens after
		// having released the lock, so other threads are not blocked anymore.
		processEntriesHelper(localQueue, logFile);

		lock.lock();
	}
}

void Logger::processEntriesHelper(queue<string>& queue, ofstream& ofs) const
{
	while (!queue.empty()) {
		ofs << queue.front() << endl;
		queue.pop();
	}
}
