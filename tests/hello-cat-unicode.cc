/* Portable Unicode Hello world */

#include <iostream>
#include <string>
#ifdef _MSC_VER
#include <codecvt>
#include <fcntl.h>
#include <io.h>
#endif
int main()
{
	std::string text = u8"hello, кошка 猫 🐱";

#ifndef _MSC_VER
	// Unicode supported (Linux etc)
	std::cout << text << '\n';
#else
	// Unicode not supported (Windows)
	_setmode(_fileno(stdout), _O_WTEXT);
	std::wstring ws = std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>{}.from_bytes(text);
	std::wcout << ws << '\n';
#endif
}
