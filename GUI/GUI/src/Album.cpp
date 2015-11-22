#include "Album.h"

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