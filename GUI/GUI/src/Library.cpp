#include "Library.h"

Library::Library() {
	artistList = gcnew List<Artist^>();

	artistList->Add(gcnew Artist("Atest"));
	artistList->Add(gcnew Artist("Ctest"));
	artistList->Add(gcnew Artist("Dtest"));
	artistList->Add(gcnew Artist("Etest"));
	artistList->Add(gcnew Artist("Btest"));
}

List<Artist^>^ Library::getArtistList() {
	return artistList;
}


void Library::import(String^ dir) {
	array<String^>^ validExtentions = { "*.flac", "*.wav", "*.ogg" };
	List<String^>^ files;

	for each (String^ s in validExtentions) {
		array<String^>^ temp = Directory::GetFiles(dir, s, SearchOption::AllDirectories);
		for each (String^ file in temp) {
			files->Add(file);
		}
	}

	for each (String^ file in files) {
		String^ artistName; // = getArtistMetadata();
		String^ albumName; // = getAlbumMetadata();
		String^ songName; // = getSongMetadata();

		Artist^ tempArtist;
		Album^ tempAlbum;
		Song^ tempSong;

		bool artistExists = false;
		bool albumExists = false;
		bool songExists = false;

		for (int i = 0; i < artistList->Count; i++) {
			if (artistList[i]->ArtistName == artistName) {
				Artist^ tempArtist = artistList[i];
				artistExists = true;
				break;
			}
		}

		if (!artistExists) {
			Artist^ tempArtist = gcnew Artist(artistName); // creates Artist object with the metadata as the parameters
			artistList->Add(tempArtist);
		}

		for (int i = 0; i < albumList->Count; i++) {
			if (albumList[i]->AlbumName == albumName) {
				Album^ tempAlbum = albumList[i];
				albumExists = true;
				break;
			}
		}

		if (!albumExists) {
			Album^ tempAlbum = gcnew Album(albumName); // creates Artist object with the metadata as the parameters
			tempAlbum->setParentArtist(tempArtist);
			tempArtist->addAlbum(tempAlbum);
			albumList->Add(tempAlbum);
		}

		for (int i = 0; i < songList->Count; i++) {
			if (songList[i]->SongName == songName) {
				Song^ songName = songList[i];
				songExists = true;
				break;
			}
		}

		if (!songExists) {
			Song^ tempSong = gcnew Song(songName); // creates Artist object with the metadata as the parameters
			tempSong->setParentArtist(tempArtist);
			tempSong->setParentAlbum(tempAlbum);
			tempAlbum->addSong(tempSong);
			songList->Add(tempSong);
		}
	}
}
