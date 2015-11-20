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
