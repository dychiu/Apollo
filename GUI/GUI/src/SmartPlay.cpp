#include "Windows.h"
#include "SmartPlay.h"

SmartPlay::SmartPlay(List<Song^>^ sList)
{
	throw gcnew System::NotImplementedException();
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

String ^ SmartPlay::getCurrentApplication()
{
	throw gcnew System::NotImplementedException();
	// TODO: insert return statement here
}

String ^ SmartPlay::getValidSongs()
{
	throw gcnew System::NotImplementedException();
	// TODO: insert return statement here
}

void SmartPlay::changePreference(String ^ category, String ^ genre)
{
	throw gcnew System::NotImplementedException();
}

void SmartPlay::refreshValidSongs()
{
	throw gcnew System::NotImplementedException();
}

void SmartPlay::refreshCategory()
{
	throw gcnew System::NotImplementedException();
}

void SmartPlay::refreshActiveApplication()
{
	throw gcnew System::NotImplementedException();
}


