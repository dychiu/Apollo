#include "Windows.h"
#include "SmartPlay.h"

SmartPlay::SmartPlay() {
}

String^ SmartPlay::getActiveWindow() {
		const int buffSize = 256;
		wchar_t buffer[buffSize];
		HWND handle = GetForegroundWindow();

		if (GetWindowText(handle, buffer, buffSize) > 0)
		{
			return gcnew System::String(buffer);
		}
		return "";
}


