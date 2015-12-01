#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
	musicLibrary = gcnew Library();
	
	playingSong = new sf::Music();
	playingSong->setLoop(false);
	playingSong->setVolume(100);

	mp3Player = gcnew naudio::WaveOut();

	currentSong = nullptr;
	selectedSong = nullptr;
	smartPlayMode = false;
}

Library^ MusicPlayer::getMusicLibrary() {
	return musicLibrary;
}

void MusicPlayer::playSong()
{
	if (currentSong == nullptr) { return; }
	if (isMP3(currentSong)) {
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
	playingSong->stop();
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
	currentArtist = selectedArtist;
	currentAlbum = currentArtist->getAlbums()[0];
	currentSong = currentAlbum->getSongs()[0];
	setSelectedSong(currentSong);
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

void MusicPlayer::setSmartPlay(bool smartPlay) {
	smartPlayMode = smartPlay;
}

void MusicPlayer::setWorkPreferences(List<String^>^ _workPreferences) {
	workPreferences = _workPreferences;
}

void MusicPlayer::setGamingPreferences(List<String^>^ _gamingPreferences) {
	gamingPreferences = _gamingPreferences;
}

void MusicPlayer::setOtherPreferences(List<String^>^ _otherPreferences) {
	otherPreferences = _otherPreferences;
}

void MusicPlayer::playNextSong() {
	if (!smartPlayMode) {
		//If current song is last in album
		if (currentAlbum->getSongs()[currentAlbum->getSongs()->Count - 1] == currentSong) {
			//If the current album is the last album as well
			if (currentArtist->getAlbums()[currentArtist->getAlbums()->Count - 1] == currentAlbum) {
				//Won't change pause button back to play button though!
				//Causes a crash if playbutton is clicked now.
				Diagnostics::Debug::WriteLine("End of artist!");
				closeSong();
			}
			else {
				//Otherwise start next album with first song
				currentAlbum = currentArtist->getAlbums()[currentArtist->getAlbums()->IndexOf(currentAlbum) + 1];
				setSelectedSong(currentAlbum->getSongs()[0]);
				setCurrentSong();
				playSong();
			}
		}
		else {
			//Otherwise just play the next song in the album
			setSelectedSong(currentAlbum->getSongs()[currentAlbum->getSongs()->IndexOf(currentSong) + 1]);
			setCurrentSong();
			playSong();
		}
	}
	else {
		//Smartplay integration goes here
	}
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

bool MusicPlayer::getSmartPlay() {
	return smartPlayMode;
}

//Danger, aliasing
sf::Music* MusicPlayer::getSFML() {
	return playingSong;
}

//Danger, aliasing
naudio::IWavePlayer^ MusicPlayer::getNAudio() {
	return mp3Player;
}

//Danger, aliasing
naudio::AudioFileReader^ MusicPlayer::getNAudioReader() {
	return mp3FileReader;
}