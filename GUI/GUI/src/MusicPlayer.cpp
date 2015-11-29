#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
	musicLibrary = gcnew Library();
	
	playingSong = new sf::Music();
	playingSong->setLoop(false);
	playingSong->setVolume(100);

	mp3Player = gcnew naudio::WaveOut();

	currentSong = nullptr;
	selectedSong = nullptr;
}

Library^ MusicPlayer::getMusicLibrary() {
	return musicLibrary;
}

void MusicPlayer::playSong()
{
	if (isMP3(selectedSong)) {
		mp3Player->Play();
	}
	else {
		playingSong->play();
	}
}

void MusicPlayer::pauseSong()
{
	if (isMP3(currentSong))
		mp3Player->Pause();
	else
		playingSong->pause();
}

void MusicPlayer::seekSong(int value)
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::closeSong()
{
	if (mp3Player != nullptr) {
		//Have to delete to stop mp3 playback
		mp3Player->Stop();
		delete mp3Player;
	}
	else {
		//Don't think SFML can actually close a song
		//Stop it for now
		playingSong->stop();
	}
}

void MusicPlayer::setPlayingSong(Song^ song) {
	closeSong();

	if (isMP3(song)) {
		mp3Player = gcnew naudio::WaveOut();
		try {
			mp3FileReader = gcnew naudio::AudioFileReader(song->getFilePath());
			mp3Player->Init(mp3FileReader);
		}
		catch (System::IO::FileNotFoundException^ e) {
			Debug::WriteLine("Error: Can't open song at " + song->getFilePath());
		}
	}
	else {
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

bool MusicPlayer::isMP3(Song^ song) {
	if (Path::GetExtension(song->getFilePath()) == ".mp3")
		return true;
	else
		return false;
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
