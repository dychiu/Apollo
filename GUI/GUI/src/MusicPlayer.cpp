#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
	musicLibrary = gcnew Library();
}

Library^ MusicPlayer::getMusicLibrary() {
	return musicLibrary;
}