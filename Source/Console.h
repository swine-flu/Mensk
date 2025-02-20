#pragma once

#include <cassert>
#include <Windows.h>


constexpr COLORREF VgaPalette[256] = {
	0x000000, 0xAA0000, 0x00AA00, 0xAAAA00, 0x0000AA, 0xAA00AA, 0x0055AA, 0xAAAAAA,
	0x555555, 0xFF5555, 0x55FF55, 0xFFFF55, 0x5555FF, 0xFF55FF, 0x55FFFF, 0xFFFFFF,
	0x000000, 0x101010, 0x202020, 0x353535, 0x454545, 0x555555, 0x656565, 0x757575,
	0x8A8A8A, 0x9A9A9A, 0xAAAAAA, 0xBABABA, 0xCACACA, 0xDFDFDF, 0xEFEFEF, 0xFFFFFF,
	0xFF0000, 0xFF0041, 0xFF0082, 0xFF00BE, 0xFF00FF, 0xBE00FF, 0x8200FF, 0x4100FF,
	0x0000FF, 0x0041FF, 0x0082FF, 0x00BEFF, 0x00FFFF, 0x00FFBE, 0x00FF82, 0x00FF41,
	0x00FF00, 0x41FF00, 0x82FF00, 0xBEFF00, 0xFFFF00, 0xFFBE00, 0xFF8200, 0xFF4100,
	0xFF8282, 0xFF829E, 0xFF82BE, 0xFF82DF, 0xFF82FF, 0xDF82FF, 0xBE82FF, 0x9E82FF,
	0x8282FF, 0x829EFF, 0x82BEFF, 0x82DFFF, 0x82FFFF, 0x82FFDF, 0x82FFBE, 0x82FF9E,
	0x82FF82, 0x9EFF82, 0xBEFF82, 0xDFFF82, 0xFFFF82, 0xFFDF82, 0xFFBE82, 0xFF9E82,
	0xFFBABA, 0xFFBACA, 0xFFBADF, 0xFFBAEF, 0xFFBAFF, 0xEFBAFF, 0xDFBAFF, 0xCABAFF,
	0xBABAFF, 0xBACAFF, 0xBADFFF, 0xBAEFFF, 0xBAFFFF, 0xBAFFEF, 0xBAFFDF, 0xBAFFCA,
	0xBAFFBA, 0xCAFFBA, 0xDFFFBA, 0xEFFFBA, 0xFFFFBA, 0xFFEFBA, 0xFFDFBA, 0xFFCABA,
	0x710000, 0x71001C, 0x710039, 0x710055, 0x710071, 0x550071, 0x390071, 0x1C0071,
	0x000071, 0x001C71, 0x003971, 0x005571, 0x007171, 0x007155, 0x007139, 0x00711C,
	0x007100, 0x1C7100, 0x397100, 0x557100, 0x717100, 0x715500, 0x713900, 0x711C00,
	0x713939, 0x713945, 0x713955, 0x713961, 0x713971, 0x613971, 0x553971, 0x453971,
	0x393971, 0x394571, 0x395571, 0x396171, 0x397171, 0x397161, 0x397155, 0x397145,
	0x397139, 0x457139, 0x557139, 0x617139, 0x717139, 0x716139, 0x715539, 0x714539,
	0x715151, 0x715159, 0x715161, 0x715169, 0x715171, 0x695171, 0x615171, 0x595171,
	0x515171, 0x515971, 0x516171, 0x516971, 0x517171, 0x517169, 0x517161, 0x517159,
	0x517151, 0x597151, 0x617151, 0x697151, 0x717151, 0x716951, 0x716151, 0x715951,
	0x410000, 0x410010, 0x410020, 0x410031, 0x410041, 0x310041, 0x200041, 0x100041,
	0x000041, 0x001041, 0x002041, 0x003141, 0x004141, 0x004131, 0x004120, 0x004110,
	0x004100, 0x104100, 0x204100, 0x314100, 0x414100, 0x413100, 0x412000, 0x411000,
	0x412020, 0x412028, 0x412031, 0x412039, 0x412041, 0x392041, 0x312041, 0x282041,
	0x202041, 0x202841, 0x203141, 0x203941, 0x204141, 0x204139, 0x204131, 0x204128,
	0x204120, 0x284120, 0x314120, 0x394120, 0x414120, 0x413920, 0x413120, 0x412820,
	0x412D2D, 0x412D31, 0x412D35, 0x412D3D, 0x412D41, 0x3D2D41, 0x352D41, 0x312D41,
	0x2D2D41, 0x2D3141, 0x2D3541, 0x2D3D41, 0x2D4141, 0x2D413D, 0x2D4135, 0x2D4131,
	0x2D412D, 0x31412D, 0x35412D, 0x3D412D, 0x41412D, 0x413D2D, 0x41352D, 0x41312D,
	0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000, 0x000000,
};

/*

*/
inline void ReportError(DWORD dwErrorCode, LPCSTR szFile, INT nLine)
{
	if (dwErrorCode == ERROR_SUCCESS) return;

	static HANDLE StdErrorHdl;
	if (StdErrorHdl == NULL) {
		HANDLE hStdDevice = GetStdHandle(STD_ERROR_HANDLE);
		if (GetFileType(hStdDevice) == FILE_TYPE_DISK) {
			StdErrorHdl = hStdDevice;
		}
		else {
			StdErrorHdl = INVALID_HANDLE_VALUE;
		}
	}

	if (StdErrorHdl == INVALID_HANDLE_VALUE) return;

	DWORD dwBufferSize;
	LPTSTR pBuffer = NULL;
	if (dwBufferSize = FormatMessage(
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS |
		FORMAT_MESSAGE_ALLOCATE_BUFFER,
		NULL,
		dwErrorCode,
		MAKELANGID(LANG_ENGLISH/*LANG_NEUTRAL*/, SUBLANG_ENGLISH_US/*SUBLANG_DEFAULT*/),
		(LPTSTR)&pBuffer,
		0,
		NULL), dwBufferSize == 0) {
		MessageBox(NULL, "FormatMessage failed!", NULL, MB_OK | MB_ICONERROR);
	}

	DWORD dwBytesWritten;
	if (!WriteFile(StdErrorHdl, pBuffer, dwBufferSize, &dwBytesWritten, NULL)) {
		MessageBox(NULL, "WriteFile failed!", NULL, MB_OK | MB_ICONERROR);
	}

	LocalFree(pBuffer);
}

/*
	TODO: Error reporting
*/
class ConsoleAPIProxy {
public:
	struct Console {
		static constexpr short rows = 25;
		static constexpr short cols = 80;
	};

	ConsoleAPIProxy()
		: hWindow{ GetConsoleWindow() }
		, hMemDC{ NULL }
		, hBitmap{ NULL }
		, hOldObj{ NULL }
		, hStdIn{ GetStdHandle(STD_INPUT_HANDLE) }
		, hStdOut{ GetStdHandle(STD_OUTPUT_HANDLE) }
	{
		if (hWindow == NULL) {
		//	ReportError(ERROR_INVALID_WINDOW_HANDLE, __FILE__, __LINE__);
		}

		if (hStdIn == INVALID_HANDLE_VALUE || hStdOut == INVALID_HANDLE_VALUE) {
		//	ReportError(ERROR_INVALID_HANDLE, __FILE__, __LINE__);
		}

		/*
		if (!SetConsoleMode(hStdIn, ENABLE_PROCESSED_INPUT | ENABLE_LINE_INPUT | ENABLE_ECHO_INPUT)) {

		}
		if (!SetConsoleMode(hStdOut, ENABLE_PROCESSED_OUTPUT)) {

		}
		*/

		if (!SetConsoleCP(866)) {

		}
		if (!SetConsoleOutputCP(866)) {

		}

		CONSOLE_CURSOR_INFO cInfo = { 5, FALSE };
		if (!SetConsoleCursorInfo(hStdOut, &cInfo)) {

		}

		CONSOLE_SCREEN_BUFFER_INFOEX csbInfoEx = {};
		csbInfoEx.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		csbInfoEx.dwSize = { Console::cols, Console::rows };
		csbInfoEx.dwCursorPosition = { 0, 0 };
		csbInfoEx.wAttributes = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
		csbInfoEx.srWindow = { 0, 0, Console::cols, Console::rows };
		csbInfoEx.dwMaximumWindowSize = { Console::cols, Console::rows };
		csbInfoEx.wPopupAttributes = 0;
		csbInfoEx.bFullscreenSupported = FALSE;
		CopyMemory(csbInfoEx.ColorTable, VgaPalette, sizeof(csbInfoEx.ColorTable));

		if (!SetConsoleScreenBufferInfoEx(hStdOut, &csbInfoEx)) {
		//	ReportError(GetLastError(), __FILE__, __LINE__);
		}
	}

	~ConsoleAPIProxy()
	{
		if (hMemDC != NULL && hOldObj != NULL) {
			SelectObject(hMemDC, hOldObj);
		}
		if (hBitmap != NULL) {
			DeleteObject(hBitmap);
		}
		if (hMemDC != NULL) {
			DeleteDC(hMemDC);
		}
	}

	CHAR ReadCharacter(SHORT xpos, SHORT ypos) {
		CHAR_INFO charInfo;
		SMALL_RECT readRegion = { xpos - 1, ypos - 1, xpos, ypos };
		if (!ReadConsoleOutput(hStdOut, &charInfo, { 1, 1 }, { 0, 0 }, &readRegion)) {

		}
		return charInfo.Char.AsciiChar;
	}

	BYTE ReadAttribute(SHORT xpos, SHORT ypos) {
		CHAR_INFO charInfo;
		SMALL_RECT readRegion = { xpos - 1, ypos - 1, xpos, ypos };
		if (!ReadConsoleOutput(hStdOut, &charInfo, { 1, 1 }, { 0, 0 }, &readRegion)) {

		}
		return charInfo.Attributes;
	}

	void WriteCharacter(SHORT xpos, SHORT ypos, CHAR character, WORD attribute) {
		CHAR_INFO charInfo = { character, attribute };
		SMALL_RECT writeRegion = { xpos - 1, ypos - 1, xpos, ypos };
		if (!WriteConsoleOutput(hStdOut, &charInfo, { 1, 1 }, { 0, 0 }, &writeRegion)) {

		}
	}

	void ClearBuffer(SHORT xpos, SHORT ypos, WORD count, CHAR ch = '\0') {
		assert(0 <= xpos && xpos < Console::cols && 0 <= ypos && ypos < Console::rows);
		DWORD dwCharsWritten;
		if (!FillConsoleOutputCharacter(hStdOut, ch, count, { xpos, ypos }, &dwCharsWritten)) {

		}

		DWORD dwAttrsWritten;
		if (!FillConsoleOutputAttribute(hStdOut, 0, count, { xpos, ypos }, &dwAttrsWritten)) {

		}
	}

	void SaveBuffer(SHORT left, SHORT top, SHORT width, SHORT height) {
		assert(0 <= left && width > 0 && left + width <= Console::cols && 0 <= top && height > 0 && top + height <= Console::rows);
		SMALL_RECT readRegion = { left, top, width - 1, height - 1 };
		if (!ReadConsoleOutput(hStdOut, &buffer[0][0], { Console::cols, Console::rows }, { left, top }, &readRegion)) {

		}
	}

	void RestoreBuffer(SHORT left, SHORT top, SHORT width, SHORT height) {
		assert(0 <= left && width > 0 && left + width <= Console::cols && 0 <= top && height > 0 && top + height <= Console::rows);
		SMALL_RECT writeRegion = { left, top, width - 1, height - 1 };
		if (!WriteConsoleOutput(hStdOut, &buffer[0][0], { Console::cols, Console::rows }, { left, top }, &writeRegion)) {

		}
	}

	void ResetBuffer() {
		CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo = {};
		screenBufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		if (!GetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}

		CopyMemory(screenBufferInfo.ColorTable, VgaPalette, sizeof(screenBufferInfo.ColorTable));

		screenBufferInfo.srWindow = { 0, 0, Console::cols, Console::rows };
		if (!SetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}

		DWORD dwCharsWritten;
		if (!FillConsoleOutputCharacter(hStdOut, ' ', Console::rows * Console::cols, { 0, 0 }, &dwCharsWritten)) {

		}

		DWORD dwAttrsWritten;
		if (!FillConsoleOutputAttribute(hStdOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED, Console::rows * Console::cols, { 0, 0 }, &dwAttrsWritten)) {

		}

		CONSOLE_CURSOR_INFO cursorInfo;
		if (!GetConsoleCursorInfo(hStdOut, &cursorInfo)) {

		}

		cursorInfo.bVisible = FALSE;
		if (!SetConsoleCursorInfo(hStdOut, &cursorInfo)) {

		}

		if (!SetConsoleCursorPosition(hStdOut, { 0, 0 })) {

		}

		if (hMemDC != NULL && hOldObj != NULL) {
			SelectObject(hMemDC, hOldObj);
			hOldObj = NULL;
		}

		if (hBitmap != NULL) {
			DeleteObject(hBitmap);
			hBitmap = NULL;
		}

		if (hMemDC != NULL) {
			DeleteDC(hMemDC);
			hMemDC = NULL;
		}
	}

	void ResetPalette() {
		CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo = {};
		screenBufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		if (!GetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}

		CopyMemory(palette, VgaPalette, sizeof(palette));
		CopyMemory(screenBufferInfo.ColorTable, VgaPalette, sizeof(screenBufferInfo.ColorTable));

		screenBufferInfo.srWindow = { 0, 0, Console::cols, Console::rows };
		if (!SetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}
	}

	void UpdatePalette() {
		CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo = {};
		screenBufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		if (!GetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}

		CopyMemory(screenBufferInfo.ColorTable, palette, sizeof(screenBufferInfo.ColorTable));

		screenBufferInfo.srWindow = { 0, 0, Console::cols, Console::rows };
		if (!SetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}
	}

	void SetPaletteRegister(BYTE regno, BYTE palid) {
		assert(regno < 16 && palid < 256);
		CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo = {};
		screenBufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		if (!GetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}

		screenBufferInfo.ColorTable[regno] = palette[palid];

		screenBufferInfo.srWindow = { 0, 0, Console::cols, Console::rows };
		if (!SetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}
	}

	// 16 pages, 16 colors per page
	void SelectColorPage(BYTE pageid) {
		assert(pageid < 16);
		CONSOLE_SCREEN_BUFFER_INFOEX screenBufferInfo = {};
		screenBufferInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
		if (!GetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}

		CopyMemory(screenBufferInfo.ColorTable, &palette[pageid * 16], sizeof(screenBufferInfo.ColorTable));

		screenBufferInfo.srWindow = { 0, 0, Console::cols, Console::rows };
		if (!SetConsoleScreenBufferInfoEx(hStdOut, &screenBufferInfo)) {

		}
	}

	void GetPaletteColor(BYTE palid, BYTE* red, BYTE* green, BYTE* blue) {
		assert(red != NULL && green != NULL && blue != NULL);
		*red = (palette[palid] & 0xFF) >> 2;
		*green = (palette[palid] >> 8 & 0xFF) >> 2;
		*blue = (palette[palid] >> 16 & 0xFF) >> 2;
	}

	void SetPaletteColor(BYTE palid, BYTE red, BYTE green, BYTE blue) {
		assert(red < 64 && green < 64 && blue < 64);
		COLORREF color = (red << 2 | red >> 4) | (green << 2 | green >> 4) << 8 | (blue << 2 | blue >> 4) << 16;
		palette[palid] = color;
	}

	void InitBitmap(void** ppvBits, LONG width, LONG height) {
		assert(ppvBits != NULL);
		assert(width > 0 && height > 0);
		HDC hDC = GetDC(hWindow);
		if (hDC == NULL) {

		}

		/*
		WINDOWINFO windowInfo = { sizeof(WINDOWINFO) };
		if (!GetWindowInfo(GetConsoleWindow(), &windowInfo)) {

		}
		*/

		struct BITMAPINFO256 {
			BITMAPINFOHEADER bmiHeader;
			RGBQUAD bmiColors[256];
		};

		BITMAPINFO256 bmpInfo = {
			sizeof(BITMAPINFOHEADER),
			width,
			-height,
			1,
			8,
			BI_RGB,
			0,	// width x height
			0,
			0,
			0,
			0
		};

		hMemDC = CreateCompatibleDC(hDC);
		if (hMemDC == NULL) {

		}

		hBitmap = CreateDIBSection(hMemDC, (BITMAPINFO*)&bmpInfo, DIB_RGB_COLORS, ppvBits, NULL, 0);
		if (hBitmap == NULL) {

		}

		hOldObj = SelectObject(hMemDC, hBitmap);
		if (hOldObj == NULL) {

		}

		ReleaseDC(hWindow, hDC);
	}

	void DrawBitmap() {
		HDC hDC = GetDC(hWindow);
		if (hDC == NULL) {

		}

		WINDOWINFO windowInfo = {};
		windowInfo.cbSize = sizeof(WINDOWINFO);
		if (!GetWindowInfo(hWindow, &windowInfo)) {

		}

		RGBQUAD rgbColors[256];
		for (int i = 0; i < 256; i++) {
			rgbColors[i] = { static_cast<BYTE>(palette[i] >> 16), static_cast<BYTE>(palette[i] >> 8), static_cast<BYTE>(palette[i]), 0 };
		}
		UINT entries = SetDIBColorTable(hMemDC, 0, 256, rgbColors);

		DIBSECTION dibSection = {};
		if (!GetObject(hBitmap, sizeof(DIBSECTION), &dibSection)) {

		}

		if (!StretchBlt(
			hDC,
			0,
			0,
			windowInfo.rcClient.right - windowInfo.rcClient.left,
			windowInfo.rcClient.bottom - windowInfo.rcClient.top,
			hMemDC,
			0,
			0,
			dibSection.dsBm.bmWidth,
			dibSection.dsBm.bmHeight,
			SRCCOPY
		)) {

		}

		ReleaseDC(hWindow, hDC);
	}

	void HideCursor() {
		CONSOLE_CURSOR_INFO cursorInfo;
		if (!GetConsoleCursorInfo(hStdOut, &cursorInfo)) {

		}

		cursorInfo.bVisible = FALSE;
		if (!SetConsoleCursorInfo(hStdOut, &cursorInfo)) {

		}
	}

	void ShowCursor() {
		CONSOLE_CURSOR_INFO cursorInfo;
		if (!GetConsoleCursorInfo(hStdOut, &cursorInfo)) {

		}

		cursorInfo.bVisible = TRUE;
		if (!SetConsoleCursorInfo(hStdOut, &cursorInfo)) {

		}
	}

	void SetCursorPositon(SHORT xpos, SHORT ypos) {
		COORD cursor{ xpos - 1, ypos - 1 };
		if (!SetConsoleCursorPosition(hStdOut, cursor)) {

		}
	}

	void WaitForInput() {
		while (TRUE) {
			DWORD dwEventsRead;
			INPUT_RECORD input;
			if (!ReadConsoleInput(hStdIn, &input, 1, &dwEventsRead)) {

			}
			if (dwEventsRead > 0 && input.EventType == KEY_EVENT && input.Event.KeyEvent.bKeyDown == TRUE &&
				(input.Event.KeyEvent.uChar.AsciiChar != '\0' || (input.Event.KeyEvent.dwControlKeyState & 0x001F) == 0) ) {
				break;
			}
		}
	}

	void GetKeyboardInput(BYTE* keyScanCode, BYTE* keyAsciiChar) {
		while (TRUE) {
			DWORD dwEventsRead;
			INPUT_RECORD input;
			if (!ReadConsoleInput(hStdIn, &input, 1, &dwEventsRead)) {

			}
			if (dwEventsRead > 0 && input.EventType == KEY_EVENT && input.Event.KeyEvent.bKeyDown == TRUE &&
				(input.Event.KeyEvent.uChar.AsciiChar != '\0' || (input.Event.KeyEvent.dwControlKeyState & 0x001F) == 0) ) {
				*keyScanCode = input.Event.KeyEvent.wVirtualScanCode;
				*keyAsciiChar = input.Event.KeyEvent.uChar.AsciiChar;
				break;
			}
		}
	}

	BOOL CheckKeyboardInput() {
		DWORD dwEventsRead;
		INPUT_RECORD input;
		if (!PeekConsoleInput(hStdIn, &input, 1, &dwEventsRead)) {

		}
		if (dwEventsRead > 0) {
			if (dwEventsRead > 0 && input.EventType == KEY_EVENT && input.Event.KeyEvent.bKeyDown == TRUE &&
				(input.Event.KeyEvent.uChar.AsciiChar != '\0' || (input.Event.KeyEvent.dwControlKeyState & 0x001F) == 0) ) {
				return TRUE;
			}
			if (!ReadConsoleInput(hStdIn, &input, dwEventsRead, &dwEventsRead)) {

			}
		}
		return FALSE;
	}

	void ClearInputBuffer() {
		if (!FlushConsoleInputBuffer(hStdIn)) {

		}
	}

	void SetWindowTitle(LPCSTR pszTitle) {
		if (!SetConsoleTitle(pszTitle)) {

		}
	}

private:
	HWND hWindow;

	HDC hMemDC;
	HBITMAP hBitmap;
	HGDIOBJ hOldObj;

	HANDLE hStdIn;
	HANDLE hStdOut;

private:
	COLORREF palette[256];
	CHAR_INFO buffer[Console::rows][Console::cols];
};
