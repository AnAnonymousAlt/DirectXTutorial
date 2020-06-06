#include <Windows.h>

int WINAPI WinMain ( HINSTANCE hInstance, 
					 HINSTANCE hPreInstance, 
					 LPSTR lpCmdLine, 
					 int nCmdShow )
{
	MessageBox ( NULL, L"Hello world",
				 L"Just another Hello World program!",
				 MB_ICONEXCLAMATION | MB_OK );
	return 0;
}