#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
	musicLibrary = gcnew Library();
	
	playingSong = new sf::Music();
	playingSong->setLoop(false);
	playingSong->setVolume(50);
}

Library^ MusicPlayer::getMusicLibrary() {
	return musicLibrary;
}

//plays the current song
//will be changed later
void MusicPlayer::playSong()
{
	//Note how taglib# accepts System::String^ and SFML accepts std::string
	//Use String() to convert
	/*std::string filepath = "../GUI/test/scholarships.flac";
	System::String^ managedPath = gcnew System::String(filepath.c_str());
	if (!playingSong->openFromFile(filepath)) {
		System::Diagnostics::Debug::WriteLine("Error: Can't open song at {1}", managedPath);
	}
	else {
		playingSong->play();
		System::Diagnostics::Debug::WriteLine("Playing song!");

		//TagLib# example
		TagLib::File^ tagFile = TagLib::File::Create(managedPath);
		System::String^ name = tagFile->Tag->Title;
		System::String^ artist = tagFile->Tag->FirstArtist;
		System::Diagnostics::Debug::WriteLine("Song: " + name + " - Artist: " + artist);
	}*/
	playingSong->play();
}

void MusicPlayer::pauseSong()
{
	playingSong->pause();
}

void MusicPlayer::seekSong(int value)
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::closeSong()
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setPlayingSong(std::string filepath) {
	//Create managed string for debug::writeline
	System::String^ managedPath = gcnew System::String(filepath.c_str());

	if (!playingSong->openFromFile(filepath)) {
		Debug::WriteLine("Error: Can't open song at {1}", managedPath);
	}
}

void MusicPlayer::setVolume(int value)
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setCurrentSong(Song _currentSong)
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setCurrentAlbum(Album _currentAlbum)
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setCurrentArtist(Artist _currentArtist)
{
	throw gcnew System::NotImplementedException();
}


void MusicPlayer::setSelectedSong(Song newSelection)
{
	throw gcnew System::NotImplementedException();
}
/*
void MusicPlayer::setSelectedAlbum(Album newSelection)
{
	throw gcnew System::NotImplementedException();
}*/

void MusicPlayer::setSelectedArtist(Artist newSelection)
{
	throw gcnew System::NotImplementedException();
}

Song MusicPlayer::getSelectedSong()
{	
	throw gcnew System::NotImplementedException();
	//Needs Song to have a copy constructor
	//return selectedSong;
}

/*Album MusicPlayer::getSelectedAlbum()
{
	//return Album();
}*/

Artist MusicPlayer::getSelectedArtist()
{
	throw gcnew System::NotImplementedException();
	//Needs Artist to have a copy constructor
	//return selectedArtist;
}

Song MusicPlayer::getCurrentSong()
{
	throw gcnew System::NotImplementedException();
	//Needs Song to have a copy constructor
	//return currentSong;
}

Album MusicPlayer::getCurrentAlbum()
{
	throw gcnew System::NotImplementedException();
	//Needs Album to have a copy constructor
	//return currentAlbum;
}

Artist MusicPlayer::getCurrentArtist()
{
	throw gcnew System::NotImplementedException();
	//Needs Artist to have a copy constructor
	//return currentArtist;
}
