#pragma once
//#include "Library.h"
#include "Artist.h"
#include "Song.h"

using namespace System;

ref class Artist;
ref class Song;
ref class Album {
public:
	Album();
	Album(TagLib::File^ tagFile);
	Album(System::String^ _name);
	System::String^ getName();
	Drawing::Image^ getAlbumArt();
	System::String^ getArtworkLocation();
	void addSong(Song^ s);
	void setParentArtist(Artist^ artist);
	Artist^ getParentArtist();
private:
	System::String^ name;
	System::String^ artworkLocation;
	List<Song^> songList;
	Drawing::Image^ art;
	Artist^ parentArtist;
};