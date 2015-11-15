#pragma once

#include "../PlayerForm.h"
#include "Library.h"

public ref class MusicPlayer {
public:
	MusicPlayer();
	Library^ getMusicLibrary();
private:
	Library^ musicLibrary;
};