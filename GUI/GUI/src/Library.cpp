#include "Library.h"

Library::Library() {
	artistList = gcnew List<Artist^>();
	albumList = gcnew List<Album^>();
	songList = gcnew List<Song^>();
}

List<Artist^>^ Library::getArtistList() {
	return artistList;
}

List<String^>^ Library::getGenreList() {
	//SortedDictionary<String^, bool>^ genres = gcnew SortedDictionary<String^, bool>();
	HashSet<String^>^ genreHash = gcnew HashSet<String^>();
	for each (Song^ song in songList) {
		genreHash->Add(song->getGenre());
	}
	List<String^>^ genres = gcnew List<String^>(genreHash);
	genres->Sort();
	for each (String^ genre in genres) {
		System::Diagnostics::Debug::WriteLine(genre);
	}
	return genres;
}

// remember to include try catch block for when there are no files of extension .flac, .wav, or .ogg
void Library::import(String^ dir) {
	array<String^>^ validExtentions = { "*.mp3", "*.flac", "*.wav", "*.ogg" };
	List<String^>^ files = gcnew List<String^>();

	for each (String^ s in validExtentions) {
		try {
			array<String^>^ temp = Directory::GetFiles(dir, s, SearchOption::AllDirectories);
			for each (String^ file in temp) {
				files->Add(file);
			}
		}
		catch (ArgumentException^ e) {
			//Cancel button was pressed
			return;
		}
	}	

	if (files->Count <= 0) {
		return;
	}

	for each (String^ file in files) {
		TagLib::File^ tagFile = TagLib::File::Create(file);		
		String^ artistName = tagFile->Tag->FirstAlbumArtist;

		//If no album artist tag, check artist and use that if present
		//otherwise set as 'Unknown'
		if (artistName == nullptr || artistName == " ") {
			if (tagFile->Tag->FirstArtist == nullptr || tagFile->Tag->FirstArtist == " ") {
				artistName = "Unknown";
			}
			artistName = tagFile->Tag->FirstArtist;
		}

		String^ albumName = tagFile->Tag->Album;
		String^ songName = tagFile->Tag->Title;

		Artist^ tempArtist;
		Album^ tempAlbum;
		Song^ tempSong;

		bool artistExists = false;
		bool albumExists = false;
		bool songExists = false;

		for (int i = 0; i < artistList->Count; i++) {
			if (artistList[i]->ArtistName == artistName) {
				tempArtist = artistList[i];
				artistExists = true;
				break;
			}
		}

		if (!artistExists) {
			tempArtist = gcnew Artist(artistName); // creates Artist object with the metadata as the parameters
			artistList->Add(tempArtist);
		}

		for (int i = 0; i < albumList->Count; i++) {
			if (albumList[i]->getName() == albumName &&
					albumList[i]->getParentArtist()->getName() == tempArtist->getName()) {
				tempAlbum = albumList[i];
				albumExists = true;
				break;
			}
		}

		if (!albumExists) {
			tempAlbum = gcnew Album(tagFile); // creates Artist object with the metadata as the parameters
			tempAlbum->setParentArtist(tempArtist);
			tempArtist->addAlbum(tempAlbum);
			albumList->Add(tempAlbum);
		}

		for (int i = 0; i < songList->Count; i++) {
			if (songList[i]->getSongName() == songName) {
				tempSong = songList[i];
				songExists = true;
				break;
			}
		}

		if (!songExists) {
			tempSong = gcnew Song(tagFile, file); // creates Artist object with the metadata as the parameters
			tempSong->setParentArtist(tempArtist);
			tempSong->setParentAlbum(tempAlbum);
			tempAlbum->addSong(tempSong);
			songList->Add(tempSong);
		}
	}
	artistList->Sort(gcnew Comparison<Artist^>(Artist::sortArtist));
}

//n^3 so room for improvement
void Library::save()
{
	XmlWriterSettings^ xmlSettings = gcnew XmlWriterSettings();
	xmlSettings->Indent = true;
	XmlWriter^ xmlFile = XmlWriter::Create("apollo.xml", xmlSettings);
	xmlFile->WriteStartDocument(true);
	xmlFile->WriteStartElement("apollo");

	xmlFile->WriteStartElement("settings");
	//////////////////////////////
	//put settings between these//
	//////////////////////////////
	xmlFile->WriteEndElement();

	xmlFile->WriteStartElement("library");
	if (artistList->Count > 0) {
		for each (Artist^ artist in artistList) {
			xmlFile->WriteStartElement("artist");
			xmlFile->WriteStartElement("name");
			xmlFile->WriteString(artist->getName());
			xmlFile->WriteEndElement();
			for each (Album^ album in artist->getAlbums()) {
				xmlFile->WriteStartElement("album");
				xmlFile->WriteStartElement("name");
				xmlFile->WriteString(album->getName());
				xmlFile->WriteEndElement();
				for each (Song^ song in album->getSongs()) {
					xmlFile->WriteStartElement("song");
					//song name
					xmlFile->WriteStartElement("name");
					xmlFile->WriteString(song->getSongName());
					xmlFile->WriteEndElement();
					//track number
					xmlFile->WriteStartElement("track");
					xmlFile->WriteString(song->getTrackNumber().ToString());
					xmlFile->WriteEndElement();
					//genre
					xmlFile->WriteStartElement("genre");
					xmlFile->WriteString(song->getGenre());
					xmlFile->WriteEndElement();
					//bpm
					xmlFile->WriteStartElement("bpm");
					xmlFile->WriteString(song->getBPM().ToString());
					xmlFile->WriteEndElement();
					//filepath
					xmlFile->WriteStartElement("filepath");
					xmlFile->WriteString(song->getFilePath());
					xmlFile->WriteEndElement();

					xmlFile->WriteEndElement();
				}
				xmlFile->WriteEndElement();
			}
			xmlFile->WriteEndElement();
		}
	}
	xmlFile->WriteEndElement();
	xmlFile->WriteEndDocument();
	xmlFile->Close();

	Diagnostics::Debug::WriteLine("XML document saved to " + Directory::GetCurrentDirectory());
}

//n^3 so room for improvement
void Library::load() {
	XmlDocument^ xmlFile = gcnew XmlDocument();
	try {
		xmlFile->Load(Directory::GetCurrentDirectory() + "\\apollo.xml");
	}
	catch (XmlException^ e) {
		//is empty file
		return;
	}
	XmlNode^ root = xmlFile->DocumentElement;
	//maybe not needed
	try {
		xmlFile->SelectSingleNode("artist");
	}
	catch (XmlException^ e) {
		//no artists listed
		return;
	}
	for each (XmlNode^ artist in root->ChildNodes[1]->ChildNodes) {
		Artist^ tempArtist = gcnew Artist();
		//Get the artist metadata
		tempArtist->setName(artist->SelectSingleNode("name")->InnerText);
		artistList->Add(tempArtist);
		for each (XmlNode^ album in artist->SelectNodes("album")) {
			Album^ tempAlbum = gcnew Album();
			//Get the album metadata
			tempAlbum->setName(album->FirstChild->InnerText);
			//Art requires filepath, take the first song and use that for the art?
			tempAlbum->setAlbumArt(album->ChildNodes[1]->SelectSingleNode("filepath")->InnerText);
			tempAlbum->setParentArtist(tempArtist);
			tempArtist->addAlbum(tempAlbum);
			albumList->Add(tempAlbum);
			for each (XmlNode^ song in album->SelectNodes("song")) {
				Song^ tempSong = gcnew Song();
				//Get song metadata
				tempSong->setSongName(song->SelectSingleNode("name")->InnerText);
				tempSong->setBPM(song->SelectSingleNode("bpm")->InnerText);
				tempSong->setTrackNumber(song->SelectSingleNode("track")->InnerText);
				tempSong->setGenre(song->SelectSingleNode("genre")->InnerText);
				tempSong->setFilepath(song->SelectSingleNode("filepath")->InnerText);
				//Add to song lists
				tempSong->setParentArtist(tempArtist);
				tempSong->setParentAlbum(tempAlbum);
				tempAlbum->addSong(tempSong);
				songList->Add(tempSong);
			}
		}
	}
}