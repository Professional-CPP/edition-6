#include <Windows.h>

import std;

using namespace std;

int main()
{
	HMODULE lib{ ::LoadLibraryA("User32.dll") };
	if (!lib) {
		println("Unable to load User32.dll.");
		return 1;
	}

	using MessageBoxFunction = int(*)(HWND, LPCSTR, LPCSTR, UINT);
	MessageBoxFunction messageBox{ (MessageBoxFunction)::GetProcAddress(lib, "MessageBoxA") };
	if (!messageBox) {
		println("Unable to get the address of MessageBoxA().");
		return 2;
	}

	messageBox(NULL, "Hello World!", "ProC++", MB_OK);
}
