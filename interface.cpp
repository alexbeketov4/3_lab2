﻿
#include "framework.h"
#include "3_lab2().h"
#include "LinkedListSequence.h"
#include "BubbleSort.h"
#include "Tests.h"
#include <sstream>
#include <vector>
#include <string>
#include <memory>

#define MAX_LOADSTRING 100
#define IDC_MAIN_EDIT 101
#define IDC_MAIN_BUTTON 102
#define IDC_DISPLAY_SEQUENCE 103
#define IDC_BUBBLESORT_BUTTON 104
#define IDC_INSERTIONSORT_BUTTON 105
#define IDC_BINARYINSERTIONSORT_BUTTON 106

ShrdPtr<Sequence<int>> sequence;

HINSTANCE hInst;                              
WCHAR szTitle[MAX_LOADSTRING];               
WCHAR szWindowClass[MAX_LOADSTRING];           

ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

std::vector<int> ParseInput(const std::wstring& input) 
{
    std::wstringstream stream(input);
    std::vector<int> result;
    int num;
    while (stream >> num) 
    {
        result.push_back(num);
    }
    return result;
}

void DisplaySequence(HWND hWnd) 
{
    std::wstring sequenceStr;
    for (int i = 0; i < sequence->GetLength(); i++) 
    {
        sequenceStr += std::to_wstring(sequence->Get(i)) + L" ";
    }
    SetWindowText(GetDlgItem(hWnd, IDC_DISPLAY_SEQUENCE), sequenceStr.c_str());
}

void RunTests()
{
    TestBubbleSortInt();
    TestBubbleSortByYearOfBirth();
    TestBubbleSortByLastname();
    TestBubbleSortByHeight();
    TestBubbleSortByWeight();

    TestInsertionSortInt();
    TestInsertionSortByYearOfBirth();
    TestInsertionSortByLastname();
    TestInsertionSortByHeight();
    TestInsertionSortByWeight();

    TestBinaryInsertionSortInt();
    TestBinaryInsertionSortByYearOfBirth();
    TestBinaryInsertionSortByLastname();
    TestBinaryInsertionSortByHeight();
    TestBinaryInsertionSortByWeight();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);


    try
    {
        RunTests();
    }
    catch (const std::out_of_range& e)
    {
        MessageBox(NULL, L"Something wrong with tests", L"Test Notification", MB_OK);
        PostQuitMessage(0);
    }

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY3LAB2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY3LAB2));

    MSG msg;

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY3LAB2));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY3LAB2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance;

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, 1000, 600, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   CreateWindowEx(0, L"EDIT", L"",
       WS_CHILD | WS_VISIBLE | WS_BORDER,
       20, 20, 300, 25, hWnd, (HMENU)IDC_MAIN_EDIT, hInstance, nullptr);

   CreateWindowEx(0, L"BUTTON", L"Create a sequence",
       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
       330, 20, 300, 25, hWnd, (HMENU)IDC_MAIN_BUTTON, hInstance, nullptr);

   CreateWindowEx(0, L"STATIC", L"",
       WS_CHILD | WS_VISIBLE | WS_BORDER,
       200, 70, 360, 25, hWnd, (HMENU)IDC_DISPLAY_SEQUENCE, hInstance, nullptr);

   CreateWindowEx(0, L"BUTTON", L"BubbleSort",
       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
       80, 130, 160, 25, hWnd, (HMENU)IDC_BUBBLESORT_BUTTON, hInstance, nullptr);

   CreateWindowEx(0, L"BUTTON", L"InsertionSort",
       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
       280, 130, 160, 25, hWnd, (HMENU)IDC_INSERTIONSORT_BUTTON, hInstance, nullptr);

   CreateWindowEx(0, L"BUTTON", L"BinaryInsertionSort",
       WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
       480, 130, 160, 25, hWnd, (HMENU)IDC_BINARYINSERTIONSORT_BUTTON, hInstance, nullptr);

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static WCHAR inputText[256];
    switch (message)
    {
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case IDC_MAIN_BUTTON:
        {
            HWND hEdit = GetDlgItem(hWnd, IDC_MAIN_EDIT);
            GetWindowText(hEdit, inputText, 256);

            auto values = ParseInput(inputText);
            if (values.empty())
            {
                MessageBox(hWnd, L"Enter a sequence", L"Error", MB_OK);
                return 0;
            }

            sequence.reset(new LinkedListSequence<int>());
            for (const int& value : values)
            {
                sequence->Append(value);
            }

            MessageBox(hWnd, L"The sequence has been created", L"", MB_OK);
            DisplaySequence(hWnd);
            break;
        }

        case IDC_BUBBLESORT_BUTTON:
        {
            if (sequence)
            {
                BubbleSort<int> sorter;
                sorter.Sort(sequence);
                DisplaySequence(hWnd);
            }
            else
            {
                MessageBox(hWnd, L"First, create a sequence", L"Error", MB_OK);
            }
            break;
        }

        case IDC_INSERTIONSORT_BUTTON:
        {
            if (sequence)
            {
                InsertionSort<int> sorter;
                sorter.Sort(sequence);
                DisplaySequence(hWnd);
            }
            else
            {
                MessageBox(hWnd, L"First, create a sequence", L"Error", MB_OK);
            }
            break;
        }

        case IDC_BINARYINSERTIONSORT_BUTTON:
        {
            if (sequence)
            {
                BinaryInsertionSort<int> sorter;
                sorter.Sort(sequence);
                DisplaySequence(hWnd);
            }
            else
            {
                MessageBox(hWnd, L"First, create a sequence", L"Error", MB_OK);
            }
            break;
        }
        }
    }
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}