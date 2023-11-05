import std;

using namespace std;

using EventHandle = unsigned int;

template <typename... Args>
class Event final
{
public:
	// Adds an observer. Returns an EventHandle to unregister the observer.
	[[nodiscard]] EventHandle addObserver(function<void(const Args&...)> observer)
	{
		auto number{ ++m_counter };
		m_observers[number] = move(observer);
		return number;
	}

	// Unregisters the observer pointed to by the given handle.
	void removeObserver(EventHandle handle)
	{
		m_observers.erase(handle);
	}

	// Raise event: notifies all registered observers.
	void raise(const Args&... args)
	{
		for (const auto& [_, callback] : m_observers) {
			callback(args...);
		}
	}

private:
	unsigned int m_counter{ 0 };
	map<EventHandle, function<void(const Args&...)>> m_observers;
};



class ObservableSubject
{
public:
	EventHandle registerDataModifiedObserver(const auto& observer) { return m_eventDataModified.addObserver(observer); }
	void unregisterDataModifiedObserver(EventHandle handle) { m_eventDataModified.removeObserver(handle); }

	EventHandle registerDataDeletedObserver(const auto& observer) { return m_eventDataDeleted.addObserver(observer); }
	void unregisterDataDeletedObserver(EventHandle handle) { m_eventDataDeleted.removeObserver(handle); }

	void modifyData()
	{
		// ...
		m_eventDataModified.raise(1, 2.3);
	}

	void deleteData()
	{
		// ...
		m_eventDataDeleted.raise();
	}

private:
	Event<int, double> m_eventDataModified;
	Event<> m_eventDataDeleted;
};



void modified(int a, double b)
{
	println("modified({}, {})", a, b);
}



class Observer final
{
public:
	explicit Observer(ObservableSubject& subject) : m_subject{ subject }
	{
		m_subjectModifiedHandle = m_subject.registerDataModifiedObserver(
			[this](int i, double d) { onSubjectModified(i, d); });
	}

	~Observer()
	{
		m_subject.unregisterDataModifiedObserver(m_subjectModifiedHandle);
	}

private:
	void onSubjectModified(int a, double b)
	{
		println("Observer::onSubjectModified({}, {})", a, b);
	}

	ObservableSubject& m_subject;
	EventHandle m_subjectModifiedHandle;
};


int main()
{
	ObservableSubject subject;

	auto handleModified{ subject.registerDataModifiedObserver(modified) };
	auto handleDeleted{ subject.registerDataDeletedObserver(
		[] { println("deleted"); }) };
	Observer observer{ subject };

	subject.modifyData();
	subject.deleteData();

	println("");

	subject.unregisterDataModifiedObserver(handleModified);
	subject.modifyData();
	subject.deleteData();
}