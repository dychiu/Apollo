#pragma once
#include "Library.h"
#include "artist.h"
#include "Song.h"

public ref class Album {
public:
	Album();
	Album(TagLib::File^ tagFile);
	Album(System::String^ _name);
	System::String^ getName();
	Drawing::Image^ getAlbumArt();
	System::String^ getArtworkLocation();
	void addSong(Song^ s);
private:
	System::String^ name;
	System::String^ artworkLocation;
	List<Song^> songList;
	Drawing::Image^ art;
};