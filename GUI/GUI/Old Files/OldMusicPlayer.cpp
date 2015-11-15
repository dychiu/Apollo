#include "MusicPlayer.h"

using namespace GUI;

MusicPlayer::MusicPlayer()
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew PlayerForm());
}

MusicPlayer::~MusicPlayer()
{
	//delete library
}

void MusicPlayer::resumeSong()
{
	std::string filepath = "../GUI/test/scholarships.flac";
	if (!currentSFML.openFromFile(filepath)) {
		System::Diagnostics::Debug::WriteLine("Can't open file!");
	}
	else {
		System::Diagnostics::Debug::WriteLine("Playing!");
		currentSFML.setLoop(true);
		currentSFML.setVolume(50);
		currentSFML.play();
	}
}
