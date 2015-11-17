#pragma once

#include "../PlayerForm.h"
#include "Library.h"
#include "artist.h"
#include "Album.h"
#include "Song.h"

#include "SFML/Audio.hpp"

public ref class MusicPlayer {
public:
	MusicPlayer();
	Library^ getMusicLibrary();


	void playSong();
	void pauseSong();
	void seekSong(int value);
	void closeSong();
	void setVolume(int value);

	//void setSelectedSong(Song newSelection);
	//void setSelectedAlbum(Album newSelection);
	void setSelectedArtist(Artist newSelection);

	//Song getSelectedSong();
	//Album getSelectedAlbum();
	Artist getSelectedArtist();
private:
	sf::Music* playingSong;
	Library^ musicLibrary;
	Song currentSong;
	Album currentAlbum;
	Artist currentArtist;

	Artist selectedArtist;
	//Album selectedAlbum;
	Song selectedSong;
	
	void setPlayingSong(std::string filepath);

};