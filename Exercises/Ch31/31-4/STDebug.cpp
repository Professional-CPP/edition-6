import std;

using namespace std;

class Logger
{
public:
	static void enableLogging(bool enable) { ms_loggingEnabled = enable; }
	static bool isLoggingEnabled() { return ms_loggingEnabled; }

	template<typename... Args>
	static void log(const Args&... args)
	{
		if (!ms_loggingEnabled) { return; }

		ofstream logfile{ ms_debugFilename, ios_base::app };
		if (logfile.fail()) {
			println("Unable to open debug file!");
			return;
		}
		print(logfile, "{:L} UTC: ", chrono::system_clock::now());
		// Use a fold-expression; see Chapter 26.
		(logfile << ... << args);
		logfile << endl;
	}

private:
	static inline const string ms_debugFilename{ "debugfile.out" };
	static inline bool ms_loggingEnabled{ false };
};

template<typename... Args>
class Log
{
public:
	explicit Log(const Args&... args,
		const source_location& location = source_location::current())
	{
		Logger::log(location.function_name(), ": ", args...);
	}
};

template <typename... Ts>
Log(Ts&&...) -> Log<Ts...>;



bool isDebugSet(int argc, char** argv)
{
	auto parameters{ views::counted(argv, argc) };
	return ranges::contains(parameters, string_view{ "-d" });
}



class ComplicatedClass
{
	// Class details omitted for brevity.
};
ostream& operator<<(ostream& outStream, const ComplicatedClass& /* src */)
{
	outStream << "ComplicatedClass";
	return outStream;
}

class UserCommand
{
	// Class details not shown for brevity.
};
ostream& operator<<(ostream& outStream, const UserCommand& /* src */)
{
	outStream << "UserCommand";
	return outStream;
}



UserCommand getNextCommand(ComplicatedClass* /* obj */)
{
	UserCommand cmd;
	return cmd;
}

void processUserCommand(const UserCommand& /* cmd */)
{
	// Details omitted for brevity.
}

void trickyFunction(ComplicatedClass* obj)
{
	Log("given argument: ", *obj);

	for (size_t i{ 0 }; i < 100; ++i) {
		UserCommand cmd{ getNextCommand(obj) };
		Log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			Log("exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char** argv)
{
	Logger::enableLogging(isDebugSet(argc, argv));

	if (Logger::isLoggingEnabled()) {
		// Print the command-line arguments to the trace.
		for (int i{ 0 }; i < argc; ++i) {
			Log("Argument: ", argv[i]);
		}
	}

	ComplicatedClass obj;
	trickyFunction(&obj);

	// Rest of the function not shown.
}
