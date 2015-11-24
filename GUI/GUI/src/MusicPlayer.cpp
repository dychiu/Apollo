#include "MusicPlayer.h"

MusicPlayer::MusicPlayer() {
	musicLibrary = gcnew Library();
	
	playingSong = new sf::Music();
	playingSong->setLoop(false);
	playingSong->setVolume(100);
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

	//Test XML Reader
	/*XmlReader^ xmlDoc = XmlReader::Create("http://www.ecb.int/stats/eurofxref/eurofxref-daily.xml");
	while (xmlDoc->Read()){
	if ((xmlDoc->NodeType == XmlNodeType::Element) && (xmlDoc->Name == "Cube"))
	{
	if (xmlDoc->HasAttributes)
	Diagnostics::Debug::WriteLine(xmlDoc->GetAttribute("currency") + ": " + xmlDoc->GetAttribute("rate"));
	}
	}
	Diagnostics::Debug::WriteLine("");
	*/

	//Test XML reading using XmlDocument --preferred
	/*XmlDocument^ xmlDoc = gcnew XmlDocument();
	xmlDoc->Load("http://www.ecb.int/stats/eurofxref/eurofxref-daily.xml");
	XmlNode^ root = xmlDoc->DocumentElement;

	Diagnostics::Debug::WriteLine(root->ChildNodes[2]->ChildNodes[0]->ChildNodes->Count);
	for each (XmlNode^ node in root->ChildNodes[2]->ChildNodes[0]->ChildNodes) {
		Diagnostics::Debug::WriteLine(node->Attributes["currency"]->Value + ": " + node->Attributes["rate"]->Value);
	}*/

	//Test XML writing
	/*XmlDocument^ xmlD = gcnew XmlDocument();
	//Example layout
	xmlD->LoadXml(L"<?xml version=\"1.0\" encoding=\"utf-8\"?>"
		L"<Apollo><settings>"
		L"</settings>"
		L"<library>"
		L"<artist><name>Drake</name>"
		L"<album><name>Fire</name>"
		L"<song><name>Scholarships</name>"
		L"<bpm>132</bpm>"
		L"<genre>Hip-Hop</genre>"
		L"<filepath>C:\\Users\\jonat\\...</filepath>"
		L"</song><song><name>Another Drake Song</name>"
		L"<genre>Hip-Hop</genre></song>"
		L"</album></artist>"
		L"</library></Apollo>");

	xmlD->Save(saveFileLoc); //exception when empty*/
	
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

void MusicPlayer::setCurrentSong()
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setCurrentAlbum()
{
	throw gcnew System::NotImplementedException();
}

void MusicPlayer::setCurrentArtist()
{
	throw gcnew System::NotImplementedException();
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
	throw gcnew System::NotImplementedException();
	//Needs Song to have a copy constructor
	//return selectedSong;
}

Artist^ MusicPlayer::getSelectedArtist()
{
	return selectedArtist;
}

Song^ MusicPlayer::getCurrentSong()
{
	throw gcnew System::NotImplementedException();
	//Needs Song to have a copy constructor
	//return currentSong;
}

Album^ MusicPlayer::getCurrentAlbum()
{
	throw gcnew System::NotImplementedException();
	//Needs Album to have a copy constructor
	//return currentAlbum;
}

Artist^ MusicPlayer::getCurrentArtist()
{
	throw gcnew System::NotImplementedException();
	//Needs Artist to have a copy constructor
	//return currentArtist;
}
