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

public:
	MediaPlayer(); //Creates GUI
	~MediaPlayer();
	void playSong(std::string filepath);
	void pauseSong(sf::Music);
	void closeSong(sf::Music);
	void setVolume(sf::Music);
	void seekSong(sf::Music);

	//Accessors
	Song getCurrentSong();
	Album getCurrentAlbum();
	Artist getCurrentArtist();
};