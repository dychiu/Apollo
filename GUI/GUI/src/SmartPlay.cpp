#include <Windows.h>
#include "SmartPlay.h"

SmartPlay::SmartPlay() {
	workApps = gcnew List<String^>();
	gamingApps = gcnew List<String^>();

	workPreferences = gcnew List<String^>();
	gamingPreferences = gcnew List<String^>();
	otherPreferences = gcnew List<String^>();

	validSongs = gcnew List<Song^>();

	initializeApps();
}

Song ^ SmartPlay::getSmartSong(List<Song^>^ _songList)
{
	songList = _songList;
	refreshValidSongs();
	Random^ rand = gcnew Random();
	if (validSongs->Count == 0) {
		return nullptr;
	}
	Song^ s = validSongs[rand->Next() % validSongs->Count];
	System::Diagnostics::Debug::Print("Selected song: " + s->getSongName() + " with genre: " + s->getGenre());
	return s;
}

String ^ SmartPlay::getActiveWindow()
{
	const int buffSize = 256;
	wchar_t buffer[buffSize];
	HWND handle = GetForegroundWindow();

	if (GetWindowText(handle, buffer, buffSize) > 0)
	{
		return gcnew String(buffer);
	}
	return "";
}

void SmartPlay::refreshValidSongs()
{
	// assign the current application
	activeApplication = getActiveWindow()->ToLower();
	System::Diagnostics::Debug::Print("Active application: " + activeApplication);

	// assign the active category
	List<String^>^ genres = otherPreferences;


	for (int i = 0; i < workApps->Count; i++) {
		if (activeApplication->Contains(workApps[i])) {
			genres = workPreferences;
		}
	}

	for (int i = 0; i < gamingApps->Count; i++) {
		if (activeApplication->Contains(gamingApps[i])) {
			genres = gamingPreferences;
		}
	}

	List<Song^>^ newValidSongs = gcnew List<Song^>;

	if (genres->Count == 0)
		genres = otherPreferences;
	// add the song to our new list of valid songs if it matches the selected genres
	for (int i = 0; i < songList->Count; i++) {
		for (int j = 0; j < genres->Count; j++) {
			if ((genres[j])->Equals(songList[i]->getGenre())) {
				newValidSongs->Add(songList[i]);
			}
		}
	}
	validSongs = newValidSongs;
}

void SmartPlay::initializeApps() {
	// work applications
	workApps->Add("outlook");
	workApps->Add("word");
	workApps->Add("excel");
	workApps->Add("powerpoint");
	workApps->Add("visual studio");
	workApps->Add("eclipse");

	// gaming applications
	gamingApps->Add("solitaire");
	gamingApps->Add("minesweeper");
}

void SmartPlay::setWorkPreferences(List<String^>^ _workPreferences) {
	workPreferences = _workPreferences;
}

void SmartPlay::setGamingPreferences(List<String^>^ _gamingPreferences) {
	gamingPreferences = _gamingPreferences;
}

void SmartPlay::setOtherPreferences(List<String^>^ _otherPreferences) {
	otherPreferences = _otherPreferences;
}

List<String^>^ SmartPlay::getWorkPreferences() {
	return workPreferences;
}

List<String^>^ SmartPlay::getGamingPreferences() {
	return  gamingPreferences;
}

List<String^>^ SmartPlay::getOtherPreferences() {
	return otherPreferences;
}