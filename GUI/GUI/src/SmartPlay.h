#pragma once
#include "LibraryObjects.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class SmartPlay {
public:
	SmartPlay(List<Song^>^ pool);
	
	// returns the active window using the Win32 API
	String^ getActiveWindow();

	// returns the active application that SmartPlay is currently using
	// to generate songs
	String^ getActiveApplication();
	
	// returns a list of valid songs based on the current active window and current
	// genre preferences. Refreshes the smart play object on call.
	List<Song^>^ getValidSongs();

	// changes the genre preferences for a selected category
	void changePreference(String^ category, String^ genre);
	
private:
	// list of all songs, from the library
	List<Song^>^ songPool;
	// list of all valid songs based on the current application
	List<Song^>^ validSongs;
	// list of applications that belong to work
	List<String^>^ work;
	// list of applications taht belong to gaming
	List<String^>^ gaming;

	// maps a category as a key to a specified genre
	Dictionary<String^, String^>^ genreMap;

	String^ activeApplication;
	String^ activeCategory;

	// updates the object upon changing the application
	void refreshValidSongs();
	void refreshCategory();
	void refreshActiveApplication();
	void initializePreferences();
};
