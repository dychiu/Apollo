#include <string>
#include <vector>

#include "Library.h"

Library::Library() {
	
}
/*
void Library::import() {
	// for (iterate through all files)
	std::string artist; // = getArtistMetadata();
	std::string album; // = getAlbumMetadata();
	std::string song; // = getSongMetadata();

	bool artistExists = false;
	bool albumExists = false;
	bool songExists = false;
	
	for (int i = 0; i < artistList.length(); i++) {
		if (artistList[i].name == artist) {
			Artist tempArtist = artistList[i];
			artistExists = true;
			break;
		}
	}

	if (artistExists == false) {
		Artist tempArtist(artist); // creates Artist object with the metadata as the parameters
		artistList.push_back(tempArtist);
	}

	for (int i = 0; i < albumList.length(); i++) {
		if (albumList[i].name == album) {
			Album tempAlbum = albumList[i];
			albumExists = true;
			break;
		}
	}

	if (albumExists == false) {
		Album tempAlbum(album); // creates Artist object with the metadata as the parameters
		tempAlbum.parentArtist = tempArtist;
		tempArtist.albums.push_back(tempAlbum);
		albumList.push_back(tempAlbum);
	}

	for (int i = 0; i < songList.length(); i++) {
		if (songList[i].name == song) {
			Song tempSong = songList[i];
			songExists = true;
			break;
		}
	}

	if (songExists == false) {
		Song tempSong(song); // creates Artist object with the metadata as the parameters
		tempSong.parentArtist = tempArtist;
		tempSong.parentAlbum = tempAlbum;
		tempAlbum.songs.push_back(tempSong);
		songList.push_back(tempSong);
	}	
}
*/