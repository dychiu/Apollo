#pragma once

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