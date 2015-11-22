#include "music-objs.h"

Artist::Artist() {}

Artist::Artist(System::String^ n) {
	name = n;
	albums = gcnew List<Album^>();
}

String^ Artist::getName() {
	return name;
}

void Artist::addAlbum(Album^ a) {
	albums->Add(a);
}

// potentially dangerous! getAlbums() currently returns a reference instead
// of a deep clone. Keep this in mind when using it and don't modify any elements
// in the array unless you want to mess up the object
List<Album^>^ Artist::getAlbums() {
	return albums;
}

Album::Album() {}

Album::Album(TagLib::File^ tagFile) {
	name = tagFile->Tag->Album;
	//Get album art
	if (tagFile->Tag->Pictures->Length > 0) {
		/*array<TagLib::IPicture^>^ pics = gcnew array<TagLib::IPicture^>[1];
		pic = tagFile->Tag->Pictures;
		System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
		art = Drawing::Image::FromStream(ms);
		*/
	}
	else {

	}
}

Album::Album(System::String^ _name) {
	name = _name;
}

System::String^ Album::getName() {
	return name;
}

Drawing::Image^ Album::getAlbumArt() {
	return art;
}

System::String^ Album::getArtworkLocation() {
	return artworkLocation;
}

void Album::addSong(Song^ s) {
	//Maybe sort by track number?
	songList.Add(s);
}

void Album::setParentArtist(Artist^ artist) {
	parentArtist = artist;
	return;
}

Artist^ Album::getParentArtist() {
	return parentArtist;
}

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

Song::Song(const Song^& copy) {
	songName = copy->songName;
	genre = copy->genre;
	filePath = copy->filePath;
	trackNumber = copy->trackNumber;
	bpm = copy->bpm;
	parentArtist = copy->parentArtist;
	parentAlbum = copy->parentAlbum;
}