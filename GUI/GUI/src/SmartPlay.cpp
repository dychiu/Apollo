#include "Windows.h"
#include "SmartPlay.h"
#include "LibraryObjects.h"

SmartPlay::SmartPlay(List<Song^>^ pool) {
	songPool = gcnew List<Song^>;
	genreMap = gcnew Dictionary<String^, String^>;
	work = gcnew List<String^>;
	gaming = gcnew List<String^>;

	for (int i = 0; i < pool->Count; i++) {
		songPool->Add(pool[i]);
	}

	initializePreferences();
	refreshValidSongs();
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

String ^ SmartPlay::getActiveApplication() {
	return activeApplication;
}

List<Song^>^ SmartPlay::getValidSongs() {
	refreshValidSongs();
	return validSongs;
}

void SmartPlay::changePreference(String ^ category, String ^ genre)
{
}

void SmartPlay::refreshValidSongs()
{
	refreshActiveApplication();
	refreshCategory();

}

void SmartPlay::refreshCategory()
{
	activeCategory = "other";
	for (int i = 0; i < work->Count; i++) {
		if (activeApplication->Contains(work[i])) {
			activeCategory = "work";
		}
	}

	for (int i = 0; i < gaming->Count; i++) {
		if (activeApplication->Contains(work[i])) {
			activeCategory = "gaming";
		}
	}
}

void SmartPlay::refreshActiveApplication()
{
	activeApplication = getActiveApplication()->ToLower();
}

void SmartPlay::initializePreferences() {
	// work applications
	work->Add("outlook");
	work->Add("word");
	work->Add("excel");
	work->Add("powerpoint");
	work->Add("visual studio");
	work->Add("eclipse");

	// gaming applications
	gaming->Add("solitaire");
	gaming->Add("minesweeper");

	genreMap["work"] = "default";
	genreMap["gaming"] = "default";
}


