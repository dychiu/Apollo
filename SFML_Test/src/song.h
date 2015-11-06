#pragma once

#include <string>
#include <boost/filesystem.hpp>
#include <SFML/Audio.hpp>

namespace fs = boost::filesystem;
class Song {

private:
	std::string name;
	std::string genre;
	fs::path file_path;
	sf::Music file_handle;
	Artist parentArtist;
	Album parentAlbum;

public:
	// One parameter constructor for the song object. Accepts a path to 
	// a music file and fills in relevant attributes based on the metadata
	// of the file.
	Song(fs::path);

	// Default destructor for the song object
	~Song();

	// Starts playing a song from the beginning
	int play();

	// Starts playing a song from a certain position
	int play(int pos);
	
	// Pauses a song, while keeping the music file open in memory
	int pause();

	// Closes a song
	int close();

	std::string get_name();
	std::string get_genre();
};