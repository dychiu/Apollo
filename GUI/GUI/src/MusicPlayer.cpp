#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
	musicLibrary = gcnew Library();
	
	playingSong = new sf::Music();
	playingSong->setLoop(false);
	playingSong->setVolume(100);

	currentSong = nullptr;
	selectedSong = nullptr;
}

Library^ MusicPlayer::getMusicLibrary() {
	return musicLibrary;
}

void MusicPlayer::playSong()
{
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
	//Don't think SFML can actually close a song
	//Stop it for now
	playingSong->stop();
}

void MusicPlayer::setPlayingSong(Song^ song) {
	std::string filepath;

	//Convert the System::String^ to std::string for SFML
	const char* chars =
		(const char*)(Runtime::InteropServices::Marshal::StringToHGlobalAnsi(song->getFilePath())).ToPointer();
	filepath = chars;
	Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr((void*)chars));

	if (!playingSong->openFromFile(filepath)) {
		Debug::WriteLine("Error: Can't open song at " + song->getFilePath());
	}

}

void MusicPlayer::setVolume(int value)
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setCurrentSong()
{

	currentSong = selectedSong;
	currentAlbum = currentSong->getParentAlbum();
	currentArtist = currentAlbum->getParentArtist();
	setPlayingSong(currentSong);
}

void MusicPlayer::setCurrentAlbum()
{
	//Probably only needed if we implement playing by double
	//clicking album art
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setCurrentArtist()
{
	//Set the artist, and then default to the first song
	//of the first album
	currentArtist = selectedArtist;
	currentAlbum = currentArtist->getAlbums()[0];
	currentSong = currentAlbum->getSongs()[0];
	setPlayingSong(currentSong);
}


void MusicPlayer::setSelectedSong(Song^ newSelection)
{
	selectedSong = newSelection;
}

void MusicPlayer::setSelectedArtist(Artist^ newSelection)
{
	selectedArtist = newSelection;
}

Song^ MusicPlayer::getSelectedSong()
{	
	return selectedSong;
}

Artist^ MusicPlayer::getSelectedArtist()
{
	return selectedArtist;
}

Song^ MusicPlayer::getCurrentSong()
{
	return currentSong;
}

Album^ MusicPlayer::getCurrentAlbum()
{
	return currentAlbum;
}

Artist^ MusicPlayer::getCurrentArtist()
{
	return currentArtist;
}
