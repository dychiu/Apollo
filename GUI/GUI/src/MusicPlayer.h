#pragma once

#include "../PlayerForm.h"
#include "Library.h"
#include "LibraryObjects.h"
#include "SFML/Audio.hpp"

#using "../../packages/NAudio-Release/NAudio.dll"
#using "../../packages/NAudio-Release/NAudio.WindowsMediaFormat.dll"

using namespace System;
using namespace System::Diagnostics;
using namespace System::Xml;
namespace naudio = NAudio::Wave;

public ref class MusicPlayer {
public:
	MusicPlayer();
	Library^ getMusicLibrary();
	
	void playSong();
	void pauseSong();
	void seekSong(int value);
	void closeSong();
	void setVolume(int value);

	void setCurrentSong();
	void setCurrentAlbum();
	void setCurrentArtist();
	void setSelectedSong(Song^ newSelection);
	void setSelectedArtist(Artist^ newSelection);

	Song^ getSelectedSong();
	Artist^ getSelectedArtist();
	Song^ getCurrentSong();
	Album^ getCurrentAlbum();
	Artist^ getCurrentArtist();
private:
	sf::Music* playingSong;
	naudio::IWavePlayer^ mp3Player;
	naudio::AudioFileReader^ mp3FileReader;

	Library^ musicLibrary;
	Song^ currentSong;
	Album^ currentAlbum;
	Artist^ currentArtist;
	Artist^ selectedArtist;
	Song^ selectedSong;
	
	void setPlayingSong(Song^ song);
	bool isMP3(Song^ song);
};