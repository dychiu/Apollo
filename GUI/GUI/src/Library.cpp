#include "Library.h"

Library::Library() {
	artistList = gcnew System::Collections::Generic::List<Artist^>();

	artistList->Add(gcnew Artist("Atest"));
	artistList->Add(gcnew Artist("Ctest"));
	artistList->Add(gcnew Artist("Dtest"));
	artistList->Add(gcnew Artist("Etest"));
	artistList->Add(gcnew Artist("Btest"));
}

System::Collections::Generic::List<Artist^>^ Library::getArtistList() {
	return artistList;
}