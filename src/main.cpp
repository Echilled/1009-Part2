<<<<<<< HEAD
#include "Game_Manager.h"
#include <iostream>
int main() {
	int PH;
	int players = 10;
	cout << "number of players: ";

	try {
		while (!(cin >> players)) {
			continue;
		}
	}
	catch (...) {
		cout << "bad\n";
	}

	cout << "chosen number of players: ";
	cout << players;
	cout << "\n";
	//Sleep(100);

	Game_Manager GM = Game_Manager(players);
	cout << "starting game\n";
	GM.Game();
	GM.Display_Results();

	cin >> PH;
}
=======
//#include <windows.h>
//
//const char g_szClassName[] = "myWindowClass";
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//    switch(msg)
//    {
//        case WM_CLOSE:
//            DestroyWindow(hwnd);
//        break;
//        case WM_DESTROY:
//            PostQuitMessage(0);
//        break;
//        default:
//            return DefWindowProc(hwnd, msg, wParam, lParam);
//    }
//    return 0;
//}
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//    LPSTR lpCmdLine, int nCmdShow)
//{
//    WNDCLASSEX wc;
//    HWND hwnd;
//    MSG Msg;
//
//    //Step 1: Registering the Window Classa
//    wc.cbSize        = sizeof(WNDCLASSEX);
//    wc.style         = 0;
//    wc.lpfnWndProc   = WndProc;
//    wc.cbClsExtra    = 0;
//    wc.cbWndExtra    = 0;
//    wc.hInstance     = hInstance;
//    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
//    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
//    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
//    wc.lpszMenuName  = NULL;
//    wc.lpszClassName = g_szClassName;
//    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);
//
//    if(!RegisterClassEx(&wc))
//    {
//        MessageBox(NULL, "Window Registration Failed!", "Error!",
//            MB_ICONEXCLAMATION | MB_OK);
//        return 0;
//    }
//
//    // Step 2: Creating the Window
//    hwnd = CreateWindowEx(
//        WS_EX_CLIENTEDGE,
//        g_szClassName,
//        "Game",
//        WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, CW_USEDEFAULT, 500, 500,
//        NULL, NULL, hInstance, NULL);
//
//    if(hwnd == NULL)
//    {
//        MessageBox(NULL, "Window Creation Failed!", "Error!",
//            MB_ICONEXCLAMATION | MB_OK);
//        return 0;
//    }
//    ShowWindow(hwnd, nCmdShow);
//    UpdateWindow(hwnd);
//
//    // Step 3: The Message Loop
//    while(GetMessage(&Msg, NULL, 0, 0) > 0)
//    {
//        TranslateMessage(&Msg);
//        DispatchMessage(&Msg);
//    }
//    return Msg.wParam;
//}
>>>>>>> 586d324d40b29c1eea13f404c6fc10e5d1aa3bf4
