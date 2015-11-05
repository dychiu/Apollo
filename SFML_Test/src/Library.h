#pragma once

#include "MusicPlayer.h"
#include "artist.h"
#include "album.h"
#include "Song.h"
#include "boost\filesystem.hpp"
#include <vector>

namespace fs = boost::filesystem;

class Library {
private:
	std::vector<Artist> artistList;
	std::vector<Song> songList;
	std::string xmlFilepath;
	std::string musicDirectory;

	std::vector<Artist> importLibrary();			//Import from musicDirectory
	std::vector<Artist> importXML();				//Import from xmlFilepath 
public:
	Library();	
	void load();		//Checks xmlFilepath
	void save();		//Saves to xmlFilepath
	void updateLibrary(); //calls importLibrary()
};