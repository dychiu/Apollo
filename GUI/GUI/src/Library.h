#pragma once
#include "LibraryObjects.h"

using namespace System;
using namespace System::IO;
using namespace System::Xml;
using namespace System::Collections::Generic;

public ref class Library {
public:
	Library();
	List<Artist^>^ getArtistList();
	
	void import(String ^dir);
	void load();
	void save();
    //void updateLibrary();

private:
	List<Artist^>^ artistList;
	List<Album^>^ albumList;
	List<Song^>^ songList;
};