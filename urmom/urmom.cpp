#include <iostream> 
#include <Windows.h> 
using namespace std;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode >= 0 && wParam == WM_KEYDOWN) {
        KBDLLHOOKSTRUCT* huy = (KBDLLHOOKSTRUCT*)lParam;
        if (huy->vkCode == '3') {

            Sleep(1000); //отсчет 1 сек.
            mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//зажатие | отпуск, корды  
        }
    }
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

int main() {
    setlocale(LC_ALL, "ru");

    HHOOK XD = SetWindowsHookEx(WH_KEYBOARD_LL, KeyboardProc, NULL, 0);
   
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg) | DispatchMessage(&msg);
    }

    UnhookWindowsHookEx(XD);
    return 0;
}//скрипт прожимает за пользователя 3ий скилл в роблоксе за сукуну не выжидая тайминга для пкм