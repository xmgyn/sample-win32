#include "framework.h"
#include "Calculator.h"
#include <windows.h>

HWND hEdit; 

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

// Entry point
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow) {
    WNDCLASS wc = { 0 };
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hInstance = hInst;
    wc.lpszClassName = L"Calculator";
    wc.lpfnWndProc = WindowProcedure;

    if (!RegisterClass(&wc))
        return -1;

    /*CreateWindow(L"Calculator", L"Simple Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 400, 500, NULL, NULL, NULL, NULL);*/
    CreateWindow(L"Calculator", L"Calculator", WS_OVERLAPPED | WS_VISIBLE | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        100, 100, 225, 395, NULL, NULL, NULL, NULL);

    MSG msg = { 0 };
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CREATE:
        hEdit = CreateWindow(L"Edit", L"", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
            55, 50, 300, 40, hWnd, NULL, NULL, NULL);
        CreateWindow(L"Button", L"1", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            5, 100, 50, 50, hWnd, (HMENU)1, NULL, NULL);
        CreateWindow(L"Button", L"2", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            55, 100, 50, 50, hWnd, (HMENU)2, NULL, NULL);
        CreateWindow(L"Button", L"3", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            105, 100, 50, 50, hWnd, (HMENU)3, NULL, NULL);
        CreateWindow(L"Button", L"4", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            5, 150, 50, 50, hWnd, (HMENU)4, NULL, NULL);
        CreateWindow(L"Button", L"5", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            55, 150, 50, 50, hWnd, (HMENU)5, NULL, NULL);
        CreateWindow(L"Button", L"6", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            105, 150, 50, 50, hWnd, (HMENU)6, NULL, NULL);
        CreateWindow(L"Button", L"7", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            5, 200, 50, 50, hWnd, (HMENU)7, NULL, NULL);
        CreateWindow(L"Button", L"8", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            55, 200, 50, 50, hWnd, (HMENU)8, NULL, NULL);
        CreateWindow(L"Button", L"9", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            105, 200, 50, 50, hWnd, (HMENU)9, NULL, NULL);
        CreateWindow(L"Button", L"0", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            5, 250, 50, 50, hWnd, (HMENU)10, NULL, NULL);
        CreateWindow(L"Button", L"+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            55, 250, 50, 50, hWnd, (HMENU)11, NULL, NULL);
        CreateWindow(L"Button", L"-", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            105, 250, 50, 50, hWnd, (HMENU)12, NULL, NULL);
        CreateWindow(L"Button", L"*", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            155, 100, 50, 50, hWnd, (HMENU)13, NULL, NULL);
        CreateWindow(L"Button", L"/", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            155, 150, 50, 50, hWnd, (HMENU)14, NULL, NULL);
        CreateWindow(L"Button", L"=", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            155, 200, 50, 100, hWnd, (HMENU)15, NULL, NULL);
        CreateWindow(L"Button", L"C", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            5, 300, 200, 50, hWnd, (HMENU)16, NULL, NULL);
        break;
    case WM_COMMAND:
        if (HIWORD(wp) == BN_CLICKED) {
            wchar_t buf[256];
            GetWindowText(hEdit, buf, 256);
            int len = wcslen(buf);

            switch (LOWORD(wp)) {
            case 1: case 2: case 3: case 4: case 5:
            case 6: case 7: case 8: case 9: 
                buf[len] = L'0' + LOWORD(wp);
                buf[len + 1] = L'\0';
                break;
            case 10:
                buf[len] = L'0';
                buf[len + 1] = L'\0';
                break;
            case 11:
                buf[len] = L'+';
                buf[len + 1] = L'\0';
                break;
            case 12:
                buf[len] = L'-';
                buf[len + 1] = L'\0';
                break;
            case 13:
                buf[len] = L'*';
                buf[len + 1] = L'\0';
                break;
            case 14:
                buf[len] = L'/';
                buf[len + 1] = L'\0';
                break;
            case 15: // Equal button
                // Simple evaluation logic here
                break;
            case 16: // Clear button
                buf[0] = L'\0';
                break;
            }
            SetWindowText(hEdit, buf);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, msg, wp, lp);
    }
    return 0;
}
