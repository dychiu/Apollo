#pragma once
#include "Album.h"
using namespace System;
using namespace System::Collections::Generic;

public ref class Artist {
public:
	Artist();
	Artist(String^ name);

	String^ getName();
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