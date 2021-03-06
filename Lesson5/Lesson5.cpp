// include the basic windows hearder file
#include <Windows.h>
#include <windowsx.h>

// the WindowProc function prototype
LRESULT CALLBACK WindowProc ( HWND hWnd,
							  UINT message,
							  WPARAM wParam,
							  LPARAM lparam );

// the entry point for any Windows program
int WINAPI WinMain ( HINSTANCE hInstance,
					 HINSTANCE hPreInstance,
					 LPSTR lpCmdLine,
					 int nCmdShow )
{
	// the handle for the window, filled by a function
	HWND hWnd;
	// this struct holds information for the window class
	WNDCLASSEX wc;

	// clear out the windowclass for use
	ZeroMemory ( &wc, sizeof ( WNDCLASSEX ) );

	// fill in the struct with the needed information
	wc.cbSize = sizeof ( WNDCLASSEX );
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.hCursor = LoadCursor ( NULL, IDC_ARROW );
	wc.hbrBackground = ( HBRUSH ) COLOR_WINDOW;
	wc.lpszClassName = L"WindowClass1";

	// register the window class
	RegisterClassExW ( &wc );
	RECT wr = { 0, 0, 200, 200 };
	AdjustWindowRect ( &wr, WS_OVERLAPPEDWINDOW, FALSE );

	// create the window and use the result as the handle
	hWnd = CreateWindowExW ( NULL,
							 L"WindowClass1", // name of the window class
							 L"Our First Windowed Program", // title of the window
							 WS_OVERLAPPEDWINDOW, // window style
							 300, // x-position of the window
							 300, // y-position of the window
							 wr.right - wr.left, // width of the window
							 wr.bottom - wr.top, // height of the window
							 NULL, // we have no parent window, NULL
							 NULL, // we aren't using menus, NULL
							 hInstance, // application handle
							 NULL ); // used with multiple windows, NULL

	// display the window on the screen
	ShowWindow ( hWnd, nCmdShow );

	// enter the main loop:

	// this struct holds Windows event messages
	MSG msg;

	// <image src="http://www.directxtutorial.com/Lessons/11/A1-Win32/5/2.gif" />


	while ( TRUE )
	{
// wait for the next messages in the queue store the result in 'msg'
		if ( PeekMessage ( &msg, NULL, 0, 0, PM_REMOVE ) )
		{
			// translate keystroke messages into the right format
			TranslateMessage ( &msg );

			// send the message to the WindowProc function
			DispatchMessageW ( &msg );

			if ( msg.message == WM_QUIT )
			{
				break;
			}
		}
		else
		{

		}
	}
	// return this part of the WM_QUIT message to Windows
	return msg.wParam;
}

// this is the main message handler for the program
LRESULT CALLBACK WindowProc ( HWND hWnd, UINT message, 
							  WPARAM wParam, LPARAM lParam )
{
	// sort through and find what code to run for the message given
	switch ( message )
	{
		// this message is read when the window is closed
	case WM_DESTROY:
		//close the application entirely
		PostQuitMessage ( 0 );
		return 0;
		break;
	default:
		break;
	}

	// handle any messages the switch statement didn't
	return DefWindowProcW ( hWnd, message, wParam, lParam );
}