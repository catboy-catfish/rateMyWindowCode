#include "windowClass.h"

#include <iostream>

LRESULT CALLBACK WindowProcedure(HWND par_Hwnd, UINT par_Msg, WPARAM par_W, LPARAM par_L)
{
	switch (par_Msg)
	{
		case WM_CLOSE:
		{
			PostQuitMessage(0);
		}
	}
	
	return DefWindowProc(par_Hwnd, par_Msg, par_W, par_L);
}

windowClass::windowClass() 
{ 
	mbr_hWnd = { 0 };
	mbr_Result = NULL;
	mbr_WindowTitle = L"I should be on the title bar";
	mbr_WindowStyle = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU;
	mbr_ClassName = L"ClassName";
	mbr_Rect = { 0, 0, 1024, 768 };
}

int windowClass::Create()
{	
	WNDCLASSEX var_wc = { 0 };
	var_wc.lpszClassName = mbr_ClassName;
	var_wc.cbSize = sizeof(WNDCLASSEX);
	var_wc.lpfnWndProc = WindowProcedure;

	mbr_Result = RegisterClassEx(&var_wc);
	if (FAILED(mbr_Result)) return 1;

	mbr_hWnd = CreateWindowEx
	(
		NULL,
		mbr_ClassName,
		mbr_WindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1024,
		768,
		NULL,
		NULL,
		NULL,
		NULL
	);
	if (!mbr_hWnd) return 2;

	ShowWindow(mbr_hWnd, SW_SHOW);
	UpdateWindow(mbr_hWnd);

	MSG var_msg;
	
	while (true)
	{
		if (PeekMessage(&var_msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&var_msg);
			DispatchMessage(&var_msg);
		}

		if (var_msg.message == WM_QUIT) break;
	}

	return 0;
}


windowClass::~windowClass() {}
