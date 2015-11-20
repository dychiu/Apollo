#include "Song.h"

Song::Song() {

}

Song::Song(TagLib::File^ tagFile, System::String^ path) {
	filePath = path;
	songName = tagFile->Tag->Title;
	genre = tagFile->Tag->FirstGenre;
	trackNumber = tagFile->Tag->Track;
	bpm = tagFile->Tag->BeatsPerMinute;
}

void Song::setParentArtist(Artist^ artist) {
	parentArtist = artist;
	return;
}

void Song::setParentAlbum(Album^ album) {
	parentAlbum = album;
	return;
}

System::String^ Song::getSongName() {
	return songName;
}

System::String^ Song::getGenre() {
	return genre;
}

System::String^ Song::getFilePath() {
	return filePath;
}

int Song::getTrackNumber() {
	return trackNumber;
}

int Song::getBPM() {
	return bpm;
}

Artist^ Song::getParentArtist() {
	return parentArtist;
}

Album^ Song::getParentAlbum() {
	return parentAlbum;
}