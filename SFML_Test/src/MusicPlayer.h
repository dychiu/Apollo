#pragma once

#include "Library.h"
#include "song.h"
#include "album.h"
#include "artist.h"
#include "GUI.h"

#include "SFML/Audio.hpp"



class MediaPlayer {
private:
	Library library;
	Song currentSong;
	Album currentAlbum;
	Artist currentArtist;
	sf::Music currentSFML;

public:
	MediaPlayer(); //Creates GUI
	~MediaPlayer();
	void playSong(std::string filepath);
	void pauseSong();
	void closeSong();
	void setVolume(int value);
	void seekSong(int seconds);

	//Accessors
	Song getCurrentSong();
	Album getCurrentAlbum();
	Artist getCurrentArtist();
};