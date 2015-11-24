#pragma once

using namespace System;
using namespace System::Collections::Generic;

ref class Artist;
ref class Album;
ref class Song;

public ref class Artist {
public:
	Artist();
	Artist(String^ name);

	String^ getName();
	List<Album^>^ getAlbums();
	void addAlbum(Album^ album);
	void setName(String^ _name);

	property String^ ArtistName {
		String^ get() {
			return name;
		}
	}

private:
	String^ name;
	List<Album^>^ albums;
};

public ref class Album {
public:
	Album();
	Album(TagLib::File^ tagFile);

	void addSong(Song^ s);
	void setParentArtist(Artist^ artist);
	void setName(String^ _name);
	void setAlbumArt(String^ filepath);

	System::String^ getName();
	Drawing::Image^ getAlbumArt();
	System::String^ getArtworkLocation();
	Artist^ getParentArtist();
	List<Song^>^ getSongs();
private:
	System::String^ name;
	System::String^ artworkLocation;
	List<Song^>^ songList;
	Drawing::Image^ art;
	Artist^ parentArtist;
};

public ref class Song {
public:
	Song();
	Song(TagLib::File^ tagFile, System::String^ path);
	Song(const Song^& copy);

	void setParentArtist(Artist^ artist);
	void setParentAlbum(Album^ album);
	void setSongName(String^ _name);
	void setGenre(String^ _genre);
	void setFilepath(String^ path);
	void setTrackNumber(String^ track);
	void setBPM(String^ beats);

	System::String^ getSongName();
	System::String^ getGenre();
	System::String^ getFilePath();
	int getTrackNumber();
	int getBPM();
	Artist^ getParentArtist();
	Album^ getParentAlbum();

	property String^ SongName {
		String^ get() {
			return songName;
		}
	}
private:
	System::String^ songName;
	System::String^ genre;
	System::String^ filePath;
	int trackNumber;
	int bpm;
	Artist^ parentArtist;
	Album^ parentAlbum;
};