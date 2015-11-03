#ifndef ARTIST_H
#define ARTIST_H

#include <String>
#include <vector>
#include "album.h"

class Artist {

private:
	std::string name;
	std::vector<Album> albums;

public:
	std::string get_name();
	void add_album(Album album);
};

#endif