#pragma once

#include <String>
#include <vector>
#include "album.h"

class Artist {

private:
	std::string name;
	std::vector<Album> albums;

public:
	std::string getName();
	void addAlbum(Album album);
};

