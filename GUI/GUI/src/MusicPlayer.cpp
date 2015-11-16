#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
	musicLibrary = gcnew Library();
	
	currentSong = new sf::Music();
	currentSong->setLoop(false);
	currentSong->setVolume(50);
}

Library^ MusicPlayer::getMusicLibrary() {
	return musicLibrary;
}

//plays the current song
//will be changed once 
void MusicPlayer::playSong()
{
	std::string filepath = "../GUI/test/scholarships.flac";
	if (!currentSong->openFromFile(filepath)) {
		System::Diagnostics::Debug::WriteLine("Error: Can't open song!");
	}
	else {
		currentSong->play();
		System::Diagnostics::Debug::WriteLine("Playing song!");
		System::String^ managedPath = "../GUI/test/scholarships.flac";
		TagLib::File^ tagFile = TagLib::File::Create(managedPath);
		System::String^ name = tagFile->Tag->Title;
		System::Diagnostics::Debug::WriteLine(name);
	}
}

void MusicPlayer::pauseSong()
{
	currentSong->pause();
}
