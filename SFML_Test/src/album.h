#pragma once

#include <String>
#include <vector>
#include "song.h"
#include <boost/filesystem.hpp>

class Album {

private:
	std::string name;
	std::vector<Song> songs;
	Artist parentArtist;

public:
	Album(std::string name);
	Album(std::string name, std::vector<Song> songs);
	std::string get_name();
	std::vector<std::string> get_song_names();
	void add_song(Song song);
};

