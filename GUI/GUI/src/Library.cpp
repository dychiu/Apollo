#include "Library.h"

Library::Library() {
	artistList = gcnew List<Artist^>();
	albumList = gcnew List<Album^>();
	songList = gcnew List<Song^>();
}

List<Artist^>^ Library::getArtistList() {
	return artistList;
}

// remember to include try catch block for when there are no files of extension .flac, .wav, or .ogg
void Library::import(String^ dir) {
	array<String^>^ validExtentions = { "*.flac", "*.wav", "*.ogg" };
	List<String^>^ files = gcnew List<String^>();

	for each (String^ s in validExtentions) {
		array<String^>^ temp = Directory::GetFiles(dir, s, SearchOption::AllDirectories);
		for each (String^ file in temp) {
			files->Add(file);
		}
	}	

	for each (String^ file in files) {
		TagLib::File^ tagFile = TagLib::File::Create(file);
		String^ artistName = tagFile->Tag->FirstAlbumArtist;
		String^ albumName = tagFile->Tag->Album;
		String^ songName = tagFile->Tag->Title;

		Artist^ tempArtist;
		Album^ tempAlbum;
		Song^ tempSong;

		bool artistExists = false;
		bool albumExists = false;
		bool songExists = false;

		for (int i = 0; i < artistList->Count; i++) {
			if (artistList[i]->ArtistName == artistName) {
				tempArtist = artistList[i];
				artistExists = true;
				break;
			}
		}

		if (!artistExists) {
			tempArtist = gcnew Artist(artistName); // creates Artist object with the metadata as the parameters
			artistList->Add(tempArtist);
		}

		for (int i = 0; i < albumList->Count; i++) {
			if (albumList[i]->getName() == albumName) {
				tempAlbum = albumList[i];
				albumExists = true;
				break;
			}
		}

		if (!albumExists) {
			tempAlbum = gcnew Album(tagFile); // creates Artist object with the metadata as the parameters
			tempAlbum->setParentArtist(tempArtist);
			tempArtist->addAlbum(tempAlbum);
			albumList->Add(tempAlbum);
		}

		for (int i = 0; i < songList->Count; i++) {
			if (songList[i]->getSongName() == songName) {
				tempSong = songList[i];
				songExists = true;
				break;
			}
		}

		if (!songExists) {
			tempSong = gcnew Song(tagFile, file); // creates Artist object with the metadata as the parameters
			tempSong->setParentArtist(tempArtist);
			tempSong->setParentAlbum(tempAlbum);
			tempAlbum->addSong(tempSong);
			songList->Add(tempSong);
		}
	}
}

