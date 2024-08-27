#pragma once

#include <Windows.h>

class windowClass
{
public:
	//	Public methods
	windowClass();

	int Create();
	int Release();	//	Need to find a use for this

	~windowClass();

private:
	HWND		mbr_hWnd;
	HRESULT		mbr_Result		= NULL;
	LPCWSTR		mbr_WindowTitle = L"I should be on the title bar";
	LPCWSTR		mbr_ClassName	= L"Class name";
	RECT		mbr_Rect;

private:
	bool		mbr_Running = true;	//	Need to find a use for this
};

