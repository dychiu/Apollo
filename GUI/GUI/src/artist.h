#pragma once
#include "Album.h"
using namespace System;
using namespace System::Collections::Generic;

ref class Album;
ref class Song;
public ref class Artist {
public:
	Artist();
	Artist(String^ name);

	String^ getName();
	List<Album^>^ getAlbums();
	void addAlbum(Album^ album);

	property String^ ArtistName {
		String^ get() {
			return name;
		}
	}

private:
	String^ name;
	List<Album^>^ albums;
};
