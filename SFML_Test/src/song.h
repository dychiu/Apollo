#pragma once

#include <string>
#include <boost/filesystem.hpp>
#include <SFML/Audio.hpp>

namespace fs = boost::filesystem;
class Song {

private:
	std::string name;
	std::string genre;
	fs::path filePath;
	sf::Music fileHandle; //do we need this?
	Artist parentArtist;
	Album parentAlbum;

public:
	// One parameter constructor for the song object. Accepts a path to 
	// a music file and fills in relevant attributes based on the metadata
	// of the file.
	Song(fs::path);

	// Default destructor for the song object
	~Song();

	std::string getName();
	std::string getGenre();
};