#pragma once
#include "LibraryObjects.h"

using namespace System;
using namespace System::IO;
using namespace System::Xml;
using namespace System::Collections::Generic;

public ref class Library {
public:
	Library();
	List<Song^>^ getSongList();
	List<Artist^>^ getArtistList();
	List<String^>^ getGenreList();
	void import(String ^dir);
	void load();
	void save();
	void setWorkPreferences(List<String^>^ _workPreferences);
	void setGamingPreferences(List<String^>^ _gamingPreferences);
	void setOtherPreferences(List<String^>^ _otherPreferences);
	List<String^>^ getWorkPreferences();
	List<String^>^ getGamingPreferences();
	List<String^>^ getOtherPreferences();

	// from smart play
	Song ^ getSmartSong();

	// returns the active window using the Win32 API
	String^ getActiveWindow();

	void refreshValidSongs();

	void initializeApps();

private:
	List<Artist^>^ artistList;
	List<Album^>^ albumList;
	List<Song^>^ songList;
	String^ saveFileLoc;

	// from smart play
	// list of all valid songs based on the current application
	List<Song^>^ validSongs;
	// list of applications that belong to work
	List<String^>^ work;
	// list of applications taht belong to gaming
	List<String^>^ gaming;

	String^ activeApplication;
	String^ activeCategory;

	List<String^>^ workPreferences;
	List<String^>^ gamingPreferences;
	List<String^>^ otherPreferences;

	List<String^>^ workApps;
	List<String^>^ gamingApps;
};