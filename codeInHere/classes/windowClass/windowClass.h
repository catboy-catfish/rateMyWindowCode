#pragma once

#include <Windows.h>

class windowClass
{
public:
	windowClass();

	int Create();

	~windowClass();

private:
	HWND		mbr_hWnd;
	HRESULT		mbr_Result;
	LPCWSTR		mbr_WindowTitle;
	DWORD		mbr_WindowStyle;
	LPCWSTR		mbr_ClassName;
	RECT		mbr_Rect;
};

