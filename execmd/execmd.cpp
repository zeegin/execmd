// licensed under cc by-sa 3.0

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <iostream> 
#include <Windows.h>
#include <tchar.h>

int windows_system(const char *cmd)
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	LPSTR cmdline;

	ZeroMemory(&pi, sizeof(pi));
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW;

	cmdline = _tcsdup(TEXT(cmd));

	if (!CreateProcess(NULL, cmdline, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
	{
		return 1;
	}

	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	
	return 0;
}

int main(int argc, char ** argv)
{
	if (argc < 2)
	{
		return 2;
	}

	std::string cmd;
	for (int i = 1; i < argc; i++)
	{
		cmd += argv[i];
		cmd += " ";
	}

	return windows_system(cmd.c_str());
}