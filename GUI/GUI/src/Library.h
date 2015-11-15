#pragma once

#include "Artist.h"

public ref class Library {
public:
	Library();
	System::Collections::Generic::List<Artist^>^ getArtistList();
private:
	System::Collections::Generic::List<Artist^>^ artistList;
};