#include <cstdlib>

#include "Globals.h"
#include "Mensk.h"


int main()
{
	/*
		https://devblogs.microsoft.com/commandline/understanding-windows-console-host-settings/
	*/
	std::atexit([] { /* TODO: Store conhost settings in a shortcut */ });

	Console.SetWindowTitle("Менск II");

	PROGRAM();

	return 0;
}
