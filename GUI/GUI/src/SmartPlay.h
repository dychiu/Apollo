#pragma once
#include "LibraryObjects.h"

public ref class SmartPlay {
private:
	// list of all valid songs based on the current application
	List<Song^>^ validSongs;
	// list of applications that belong to work
	List<String^>^ work;
	// list of applications that belong to gaming
	List<String^>^ gaming;
	List<String^>^ workApps;
	List<String^>^ gamingApps;
	String^ activeApplication;
	String^ activeCategory;
	List<String^>^ workPreferences;
	List<String^>^ gamingPreferences;
	List<String^>^ otherPreferences;
	List<Song^>^ songList;
public:
	SmartPlay();
	Song ^ getSmartSong(List<Song^>^ _songList);
	// returns the active window using the Win32 API
	String^ getActiveWindow();
	void refreshValidSongs();
	void initializeApps();

	void setWorkPreferences(List<String^>^ _workPreferences);
	void setGamingPreferences(List<String^>^ _gamingPreferences);
	void setOtherPreferences(List<String^>^ _otherPreferences);
	List<String^>^ getWorkPreferences();
	List<String^>^ getGamingPreferences();
	List<String^>^ getOtherPreferences();
};