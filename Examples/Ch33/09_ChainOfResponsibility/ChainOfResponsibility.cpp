import std;

using namespace std;

enum class Event {
	LeftMouseButtonDown,
	LeftMouseButtonUp,
	RightMouseButtonDown,
	RightMouseButtonUp
};

class Handler
{
public:
	virtual ~Handler() = default;

	explicit Handler(Handler* nextHandler) : m_nextHandler{ nextHandler } { }

	virtual void handleMessage(Event message)
	{
		if (m_nextHandler) { m_nextHandler->handleMessage(message); }
	}
private:
	Handler* m_nextHandler{ nullptr };
};


class Application : public Handler
{
public:
	explicit Application(Handler* nextHandler) : Handler{ nextHandler } { }

	void handleMessage(Event message) override
	{
		println("Application::handleMessage()");
		if (message == Event::RightMouseButtonDown) {
			println("   Handling message RightMouseButtonDown");
		} else {
			Handler::handleMessage(message);
		}
	}
};

class Window : public Handler
{
public:
	explicit Window(Handler* nextHandler) : Handler{ nextHandler } { }

	void handleMessage(Event message) override
	{
		println("Window::handleMessage()");
		if (message == Event::LeftMouseButtonUp) {
			println("   Handling message LeftMouseButtonUp");
		} else {
			Handler::handleMessage(message);
		}
	}
};

class Shape : public Handler
{
public:
	explicit Shape(Handler* nextHandler) : Handler{ nextHandler } { }

	void handleMessage(Event message) override
	{
		println("Shape::handleMessage()");
		if (message == Event::LeftMouseButtonDown) {
			println("   Handling message LeftMouseButtonDown");
		} else {
			Handler::handleMessage(message);
		}
	}
};


int main()
{
	Application application{ nullptr };
	Window window{ &application };
	Shape shape{ &window };

	shape.handleMessage(Event::LeftMouseButtonDown);
	println("");

	shape.handleMessage(Event::LeftMouseButtonUp);
	println("");

	shape.handleMessage(Event::RightMouseButtonDown);
	println("");

	shape.handleMessage(Event::RightMouseButtonUp);
}
