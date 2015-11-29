#pragma once
#include "LibraryObjects.h"

using namespace System;
using namespace System::Collections::Generic;

public ref class SmartPlay {
public:
	//SmartPlay(List<Song^>^ sList);
	//void addPreference(String^ application, String^ genre);
	//void changePreference(String^ application, String^ genre);
	SmartPlay();
	String ^ getActiveWindow();
	// returns a list of valid songs based on the current application
	//String^ getValidSongs();
	//String^ getCurrentApplication();
private:
	List<String^>^ knownApplications;

	// updates the list of valid songs upon changing the application
	//void refreshValidSongs();
	//void refreshCategory();
	// String^ refreshCurrentApplication();
	// maps an application as a key to a specified genre
	Dictionary<String^, String^>^ genreMap;
	// active application currently detected
	String^ activeApplication;
	String^ activeCategory;
	// list of songs that smart play knows about. Generated from the library
	List<Song^>^ songList;
	// a list of all valid songs based on the current application
	List<Song^>^ validSongs;
};
