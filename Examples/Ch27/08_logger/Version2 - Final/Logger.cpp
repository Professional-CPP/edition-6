module logger;

import std;

using namespace std;

Logger::Logger()
{
	// Start background thread.
	m_thread = thread{ &Logger::processEntries, this };
}

Logger::~Logger()
{
	{
		lock_guard lock{ m_mutex };
		// Gracefully shut down the thread by setting m_exit to true.
		m_exit = true;
	}
	// Notify condition variable to wake up thread.
	m_condVar.notify_all();
	// Wait until thread is shut down. This should be outside the above code
	// block because the lock on m_mutex must be released before calling join()!
	m_thread.join();
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
		if (!m_exit) { // Only wait for notifications if we don't have to exit.

			// You can add artificial delays on specific places in your multithreaded
			// code to trigger certain behavior. Such delays should only be added
			// for testing, and must be removed from your final code!
			//
			// For example, in this Logger class, you could add the following delay
			// to test that the race-condition with the destructor as discussed
			// in Chapter 27 is solved.
			//this_thread::sleep_for(1000ms);

			if (m_queue.empty()) { // Only wait if the queue is empty.
				m_condVar.wait(lock);
			}
		} else {
			// We have to exit, process the remaining entries in the queue.
			processEntriesHelper(m_queue, logFile);
 			break;
		}

		// Condition variable is notified, so something might be in the queue
		// and/or we need to shut down this thread.

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