import std;

using namespace std;

using EventHandle = unsigned;

template <typename... Args>
class Event
{
public:
	virtual ~Event() = default; // Always a virtual destructor!

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
		for (auto& [_, callback] : m_observers) {
			callback(args...);
		}
	}

private:
	unsigned m_counter{ 0 };
	map<EventHandle, function<void(const Args&...)>> m_observers;
};



class ObservableSubject
{
public:
	auto& getEventDataModified() { return m_eventDataModified; }
	auto& getEventDataDeleted() { return m_eventDataDeleted; }

	void modifyData()
	{
		// ...
		getEventDataModified().raise(1, 2.3);
	}

	void deleteData()
	{
		// ...
		getEventDataDeleted().raise();
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
		m_subjectModifiedHandle = m_subject.getEventDataModified().addObserver(
			[this](int i, double d) { onSubjectModified(i, d); });
	}

	~Observer()
	{
		m_subject.getEventDataModified().removeObserver(
			m_subjectModifiedHandle);
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

	auto handleModified{ subject.getEventDataModified().addObserver(modified) };
	auto handleDeleted{ subject.getEventDataDeleted().addObserver(
		[] { println("deleted"); }) };
	Observer observer{ subject };

	subject.modifyData();
	subject.deleteData();

	println("");

	subject.getEventDataModified().removeObserver(handleModified);
	subject.modifyData();
	subject.deleteData();
}