#pragma once
#include "SmartPlay.h"
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
	SmartPlay^ getSmartPlayObj();
	void import(String ^dir);
	void load();
	void save();

private:
	List<Artist^>^ artistList;
	List<Album^>^ albumList;
	List<Song^>^ songList;
	String^ saveFileLoc;
	SmartPlay^ smartPlay;
};