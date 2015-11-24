#include "LibraryObjects.h"

Artist::Artist() {
	albums = gcnew List<Album^>();
}

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

void Artist::setName(String ^ _name)
{
	name = _name;
	return;
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
	songList = gcnew List<Song^>();

	//Get album art
	if (tagFile->Tag->Pictures->Length > 0) {
		TagLib::IPicture^ pic = (TagLib::IPicture^)tagFile->Tag->Pictures[0];
		System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(pic->Data->Data);
		art = Drawing::Image::FromStream(ms);
	}
	else {
		art = nullptr;
	}
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
	songList->Add(s);
}

void Album::setParentArtist(Artist^ artist) {
	parentArtist = artist;
	return;
}

void Album::setName(String^ _name)
{
	name = _name;
	return;
}

void Album::setAlbumArt(String ^ filepath)
{
	TagLib::File^ tagFile = TagLib::File::Create(filepath);
	//Get album art
	if (tagFile->Tag->Pictures->Length > 0) {
		TagLib::IPicture^ pic = (TagLib::IPicture^)tagFile->Tag->Pictures[0];
		System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(pic->Data->Data);
		art = Drawing::Image::FromStream(ms);
	}
	else {
		art = nullptr;
	}
	return;
}

Artist^ Album::getParentArtist() {
	return parentArtist;
}

List<Song^>^ Album::getSongs() {
	return songList;
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

void Song::setSongName(String ^ _name)
{
	songName = _name;
	return;
}

void Song::setGenre(String ^ _genre)
{
	genre = _genre;
	return;
}

void Song::setFilepath(String ^ path)
{
	filePath = path;
	return;
}

void Song::setTrackNumber(String^ num)
{
	trackNumber = Convert::ToInt32(num);
	return;
}

void Song::setBPM(String^ beats)
{
	bpm = Convert::ToInt32(beats);
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