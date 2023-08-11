import ring_buffer;
import std;

using namespace std;

RingBuffer debugBuffer;

#define log(...) debugBuffer.addEntry(__func__, "(): ", __VA_ARGS__)

class ComplicatedClass
{
};
ostream& operator<<(ostream& outStream, const ComplicatedClass& /* src */)
{
	outStream << "ComplicatedClass";
	return outStream;
}

class UserCommand
{
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

void processUserCommand(UserCommand& /* cmd */)
{
	// Details omitted for brevity.
}

void trickyFunction(ComplicatedClass* obj)
{
	// Trace log the values with which this function starts.
	log("given argument: ", *obj);

	for (size_t i{ 0 }; i < 100; ++i) {
		UserCommand cmd{ getNextCommand(obj) };
		log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			log("exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
	// Log the command-line arguments.
	for (size_t i{ 0 }; i < argc; ++i) {
		log("Argument: ", argv[i]);
	}

	ComplicatedClass obj;
	trickyFunction(&obj);

	// Print the current contents of the debug buffer to cout.
	cout << debugBuffer;
}
