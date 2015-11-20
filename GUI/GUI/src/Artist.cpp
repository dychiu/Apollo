#include "Artist.h"

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