//header files
#include<windows.h>

//global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

//global variable declarations

//Entry point function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIntance, LPSTR lpszCmdLine, int iCmdShow)
{
	//local variable declarations
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR szAppName[] = TEXT("WINDEV");

	//code
	//wndclass EXE initialization
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREADRAW | CS_VREADRAW;
	wndclass.cbClsEXtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.lpszClassName = szAppName;
	wndclass.lpszMenuName = NULL;
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);


	//registration of WNDCLASSEX
	RegisterClassEx(&wndclass);

	//creating the window
	hwnd = CreateWindow(
		szAppName,
		TEXT("BSK : Window"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL);

	//show the window
	ShowWindow(hwnd, iCmdShow);

	//update window
	UpdateWindow(hwnd);

	//message loop
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT imsg,WPRAM wParam,LPARAM lParam)
{
	//Local variable declarations
	TCHAR str[255];

	//code
	switch(imsg)
	{
	case WM_CREATE :
		wsprintf(str, TEXT("WM_CREATE MESSAGE IS RECEIVED"));
		MessageBox(hwnd, str, Text("Message"), MB_OK);
		break;
	case WM_KEYDOWN :
		wsprintf(str, TEXT("WM_KEYDOWN MESSAGE IS RECEIVED"));
		MessageBox(hwnd, str, Text("Message"), MB_OK);
		break;
	case WM_LBUTTONDOWN :
		wsprintf(str, TEXT("WM_LBUTTONDOWN MESSAGE IS RECEIVED"));
		MessageBox(hwnd, str, Text("Message"), MB_OK);
		break;
	case WM_RBUTTONDOWN :
		wsprintf(str, TEXT("WM_RBUTTIONDOWN MESSAGE IS RECEIVED"));
		MessageBox(hwnd, str, Text("Message"), MB_OK);
		break;
	case WM_DESTROY :
		wsprintf(str, TEXT("WM_DESTROY MESSAGE IS RECEIVED"));
		MessageBox(hWnd, str, Text("Message"), MB_OK);
		PostQuitMessage(0);
		break;
	default :
		break;
	}
	return(DefWindowProc(hwnd, imsg, wParam, lParam));
}
