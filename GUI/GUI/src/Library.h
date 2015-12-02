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
	List<String^>^ setGamingPreferences();
	List<String^>^ setOtherPreferences();
private:
	List<Artist^>^ artistList;
	List<Album^>^ albumList;
	List<Song^>^ songList;
	String^ saveFileLoc;

	List<String^>^ workPreferences;
	List<String^>^ gamingPreferences;
	List<String^>^ otherPreferences;
};