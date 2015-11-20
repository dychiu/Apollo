#pragma once

#include "Artist.h"
#include "Album.h"

public ref class Song {
public:
	Song();
	Song(TagLib::File^ tagFile, System::String^ path);
	
	void setParentArtist(Artist^ artist);
	void setParentAlbum(Album^ album);

	System::String^ getSongName();
	System::String^ getGenre();
	System::String^ getFilePath();
	int getTrackNumber();
	int getBPM();
	Artist^ getParentArtist();
	Album^ getParentAlbum();
private:
	System::String^ songName;
	System::String^ genre;
	System::String^ filePath;
	int trackNumber;
	int bpm;
	Artist^ parentArtist;
	Album^ parentAlbum;
};