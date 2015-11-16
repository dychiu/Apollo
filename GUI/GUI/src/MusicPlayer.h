#pragma once

#include "../PlayerForm.h"
#include "Library.h"

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
	sf::Music* currentSong;
	Library^ musicLibrary;

	Artist selectedArtist;
	//Album selectedAlbum;
	//Song selectedSong;
};