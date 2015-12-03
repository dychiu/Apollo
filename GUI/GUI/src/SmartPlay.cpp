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
		return gcnew String(buffer);
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
	genreMap[category] = genre;
}

void SmartPlay::refreshValidSongs()
{
	refreshActiveApplication();
	refreshCategory();

	String^ activeGenre = genreMap[activeCategory];
	List<Song^>^ newValidSongs = gcnew List<Song^>;

	// add the song to our new list of valid songs if it matches the selected genres
	for (int i = 0; i < songPool->Count; i++) {
		if (activeGenre->Equals(songPool[i]->getGenre()->ToLower()) || activeGenre->Equals("default")) {
			newValidSongs->Add(songPool[i]);
		}
	}
	validSongs = newValidSongs;
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
	activeApplication = getActiveWindow()->ToLower();
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
	genreMap["other"] = "default";
}


