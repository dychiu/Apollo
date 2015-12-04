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
	if (albums->Count == 0) {
		albums->Add(a);
		return;
	}
	for (int i = 0; i < albums->Count; i++) {
		if (String::Compare(a->getName(),albums[i]->getName()) < 0) {
			albums->Insert(i, a);
			return;
		}
	}
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

int Artist::sortArtist(Artist^ x, Artist^ y) {
	return String::Compare(x->getName(),y->getName());
}

Album::Album() {
	songList = gcnew List<Song^>();
}

Album::Album(TagLib::File^ tagFile) {
	name = tagFile->Tag->Album;
	year = tagFile->Tag->Year;

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

int Album::getYear() {
	return year;
}

void Album::setYear(String^ _year)
{
	year = Convert::ToInt32(_year);
	return;
}

System::String^ Album::getArtworkLocation() {
	return artworkLocation;
}

void Album::addSong(Song^ s) {
	if (songList->Count == 0) {
		songList->Add(s);
		return;
	}
	for (int i = 0; i < songList->Count; i++) {
		if (s->getTrackNumber() < songList[i]->getTrackNumber()) {
			songList->Insert(i, s);
			return;
		}
	}
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