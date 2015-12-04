#include "PlayerForm.h"

using namespace GUI;

PlayerForm::PlayerForm() {
	InitializeComponent();
	// initialize play button image
	roundButton->BackgroundImage = imageList1->Images[0];
	play = false;
	// initialize smart play button image
	smartPlayButton->BackgroundImage = imageList1->Images[2];
	// initialize skip button image
	skipButton->BackgroundImage = imageList1->Images[4];
	// initialize close button image
	button1->BackgroundImage = imageList1->Images[6];
	// initialize minimiaze button image
	minimizeButton->BackgroundImage = imageList1->Images[8];
	// initialize import button image
	importButton->BackgroundImage = imageList1->Images[10];
	preferencesButton->BackgroundImage = imageList1->Images[14];
	playSymbol->BackgroundImage = imageList1->Images[13];

	musicPlayer = gcnew MusicPlayer();
	
	offsetSFML = 0;

	mouseDownProgress = false;
	mouseDownVolume = false;
	artistSelectionsCleared = false;
	songSelectionChanged = true;

	listBox1->DataSource = musicPlayer->getMusicLibrary()->getArtistList();
	listBox1->DisplayMember = "ArtistName";
	listBox1->ClearSelected();
	artistSelectionsCleared = true;

	artwork = gcnew List<PictureBox^>();
	album = gcnew List<Label^>();
	leftNumbers = gcnew List<ListBox^>();
	rightNumbers = gcnew List<ListBox^>();
	leftSongs = gcnew List<ListBox^>();
	rightSongs = gcnew List<ListBox^>();
	year = gcnew List<Label^>();
	genre = gcnew List<Label^>();

	selectedList = nullptr;

	//load existing xml file
	//for now from current directory
	if (File::Exists(Directory::GetCurrentDirectory() + "\\apollo.xml")) {
		musicPlayer->getMusicLibrary()->load();
		listBox1->DataSource = nullptr;
		listBox1->DataSource = musicPlayer->getMusicLibrary()->getArtistList();
		listBox1->DisplayMember = "ArtistName";
	}
}

System::Void PlayerForm::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}

System::Void PlayerForm::PlayerForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	ReleaseCapture();
	SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
}

System::Void PlayerForm::roundButton_Paint(Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	System::Drawing::Drawing2D::GraphicsPath^ buttonPath = gcnew System::Drawing::Drawing2D::GraphicsPath;
	// Set a new rectangle to the same size as the button's ClientRectangle property.
	System::Drawing::Rectangle newRectangle = roundButton->ClientRectangle;
	// Decrease the size of the rectangle.
	//newRectangle.Inflate(0, 0);
	// Draw the button's border.
	//e->Graphics->DrawEllipse(gcnew Pen(Color::Black), newRectangle);
	// Increase the size of the rectangle to include the border.
	//newRectangle.Inflate(1,1);
	// Create a circle within the new rectangle.
	buttonPath->AddEllipse(newRectangle);
	// Set the button's Region property to the newly created circle region.
	roundButton->Region = gcnew System::Drawing::Region(buttonPath);
}

System::Void PlayerForm::roundButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (musicPlayer->getSelectedSong() != nullptr) {
		if (musicPlayer->getSmartPlay() == false) {
			if (play == false) {				
				playSongNormal();
			}
			else if (play == true) {
				pauseSongNormal();
			}
		}
		else if (musicPlayer->getSmartPlay() == true) {
			if (play == false) {
				playSongSmart();
			}
			else if (play == true) {
				pauseSongSmart();
			}
		}
	}
}

System::Void PlayerForm::smartPlayButton_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	System::Drawing::Drawing2D::GraphicsPath^ buttonPath = gcnew System::Drawing::Drawing2D::GraphicsPath;
	System::Drawing::Rectangle newRectangle = smartPlayButton->ClientRectangle;
	buttonPath->AddEllipse(newRectangle);
	smartPlayButton->Region = gcnew System::Drawing::Region(buttonPath);
}

System::Void PlayerForm::smartPlayButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (musicPlayer->getSmartPlay() == false) {
		changeToSmart();
		musicPlayer->setSmartPlay(true);
		//play = false;
	}
	else if (musicPlayer->getSmartPlay() == true) {
		changeToNormal();
		musicPlayer->setSmartPlay(false);
		//play = false;
	}
}

void PlayerForm::changeToSmart() {
	if (play == false)
		roundButton->BackgroundImage = imageList1->Images[2];
	else
		roundButton->BackgroundImage = imageList1->Images[3];
	roundButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)));

	smartPlayButton->BackgroundImage = imageList1->Images[0];
	smartPlayButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	smartPlayButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)));

	skipButton->BackgroundImage = imageList1->Images[5];
	skipButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)));
	skipButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));

	button1->BackgroundImage = imageList1->Images[7];
	button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)));

	minimizeButton->BackgroundImage = imageList1->Images[9];
	minimizeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)));

	importButton->BackgroundImage = imageList1->Images[11];
	importButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));

	preferencesButton->BackgroundImage = imageList1->Images[15];
	preferencesButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
	
	notifyIcon1->Visible = true;

	BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)));
	progressBar1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)));

	panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));

	for (int i = 0; i < rightSongs->Count; i++) {
		leftNumbers[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
			static_cast<System::Int32>(static_cast<System::Byte>(210)));
		rightNumbers[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
			static_cast<System::Int32>(static_cast<System::Byte>(210)));
		leftSongs[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
			static_cast<System::Int32>(static_cast<System::Byte>(210)));
		rightSongs[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
			static_cast<System::Int32>(static_cast<System::Byte>(210)));		
	}
}

void PlayerForm::changeToNormal() {
	if (play == false)
		roundButton->BackgroundImage = imageList1->Images[0];
	else
		roundButton->BackgroundImage = imageList1->Images[1];
	roundButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));

	smartPlayButton->BackgroundImage = imageList1->Images[2];
	smartPlayButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)));
	smartPlayButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));

	skipButton->BackgroundImage = imageList1->Images[4];
	skipButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	skipButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)));

	button1->BackgroundImage = imageList1->Images[6];
	button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));

	minimizeButton->BackgroundImage = imageList1->Images[8];
	minimizeButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));

	importButton->BackgroundImage = imageList1->Images[10];
	importButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)));

	preferencesButton->BackgroundImage = imageList1->Images[14];
	preferencesButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
		static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)));

	notifyIcon1->Visible = false;

	BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	progressBar1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));

	panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));

	for (int i = 0; i < rightSongs->Count; i++) {
		leftNumbers[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		rightNumbers[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		leftSongs[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
		rightSongs[i]->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
			static_cast<System::Int32>(static_cast<System::Byte>(255)));
	}
}

System::Void PlayerForm::skipButton_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
	System::Drawing::Drawing2D::GraphicsPath^ buttonPath = gcnew System::Drawing::Drawing2D::GraphicsPath;
	System::Drawing::Rectangle newRectangle = skipButton->ClientRectangle;
	buttonPath->AddEllipse(newRectangle);
	skipButton->Region = gcnew System::Drawing::Region(buttonPath);
}

System::Void PlayerForm::skipButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	musicPlayer->playNextSong();
}

System::Void PlayerForm::minimizeButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}

System::Void PlayerForm::importButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	folderBrowserDialog1->ShowDialog();
	musicPlayer->getMusicLibrary()->import(folderBrowserDialog1->SelectedPath);
	artistSelectionsCleared = false;
	listBox1->DataSource = nullptr;
	artistSelectionsCleared = true;
	listBox1->DataSource = musicPlayer->getMusicLibrary()->getArtistList();
	listBox1->DisplayMember = "ArtistName";

	//Save the library after importing
	musicPlayer->getMusicLibrary()->save();
}

System::Void PlayerForm::listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (artistSelectionsCleared == true) {
		musicPlayer->setSelectedArtist(musicPlayer->getMusicLibrary()->getArtistList()[listBox1->SelectedIndex]);
		changeArtist();
	}
}

void PlayerForm::changeArtist() {
	removeComponents();
	createComponents();
}

void PlayerForm::removeComponents() {
	for (int i = 0; i < album->Count; i++) {
		panel2->Controls->Remove(artwork[i]);
		panel2->Controls->Remove(album[i]);
		panel2->Controls->Remove(leftNumbers[i]);
		panel2->Controls->Remove(rightNumbers[i]);
		panel2->Controls->Remove(leftSongs[i]);
		panel2->Controls->Remove(rightSongs[i]);
		panel2->Controls->Remove(year[i]);
		panel2->Controls->Remove(genre[i]);
	}
	artwork->Clear();
	album->Clear();
	leftNumbers->Clear();
	rightNumbers->Clear();
	leftSongs->Clear();
	rightSongs->Clear();
	year->Clear();
	genre->Clear();
}

void PlayerForm::createComponents() {
	int offset = 0;

	for (int i = 0; i < musicPlayer->getSelectedArtist()->getAlbums()->Count; i++) {

		int listSize = ceil(musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->Count / 2.0);

		//
		// album artwork
		//
		System::Windows::Forms::PictureBox^ tempArtwork = (gcnew System::Windows::Forms::PictureBox());
		tempArtwork->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;		
		tempArtwork->Location = System::Drawing::Point(0, offset + 9);
		tempArtwork->Size = System::Drawing::Size(150, 150);
		tempArtwork->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				
		Image^ pic = musicPlayer->getSelectedArtist()->getAlbums()[i]->getAlbumArt();
		if (pic == nullptr)
			tempArtwork->Image = imageList1->Images[12];
		else
			tempArtwork->Image = pic;

		panel2->Controls->Add(tempArtwork);
		artwork->Add(tempArtwork);

		//
		// album title
		//
		System::Windows::Forms::Label^ tempAlbum = (gcnew System::Windows::Forms::Label());
		tempAlbum->AutoSize = true;
		tempAlbum->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		tempAlbum->Location = System::Drawing::Point(156, offset + 10);

		tempAlbum->Text = musicPlayer->getSelectedArtist()->getAlbums()[i]->getName();

		panel2->Controls->Add(tempAlbum);
		album->Add(tempAlbum);

		//
		// left track numbers
		//
		System::Windows::Forms::ListBox^ tempLeftNumbers = (gcnew System::Windows::Forms::ListBox());
		if (musicPlayer->getSmartPlay() == false)
			tempLeftNumbers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
		else
			tempLeftNumbers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
		tempLeftNumbers->BorderStyle = System::Windows::Forms::BorderStyle::None;
		tempLeftNumbers->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		tempLeftNumbers->ForeColor = System::Drawing::SystemColors::GrayText;		
		tempLeftNumbers->Location = System::Drawing::Point(152, offset + 45);
		tempLeftNumbers->SelectionMode = System::Windows::Forms::SelectionMode::None;
		tempLeftNumbers->Size = System::Drawing::Size(22, 21 * listSize);
		tempLeftNumbers->RightToLeft = System::Windows::Forms::RightToLeft::Yes;

		tempLeftNumbers->DataSource = musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->GetRange(0, listSize);
		tempLeftNumbers->DisplayMember = "SongNumber";

		panel2->Controls->Add(tempLeftNumbers);
		leftNumbers->Add(tempLeftNumbers);

		//
		// right track numbers
		//
		System::Windows::Forms::ListBox^ tempRightNumbers = (gcnew System::Windows::Forms::ListBox());
		if (musicPlayer->getSmartPlay() == false)
			tempRightNumbers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
		else
			tempRightNumbers->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
		tempRightNumbers->BorderStyle = System::Windows::Forms::BorderStyle::None;
		tempRightNumbers->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		tempRightNumbers->ForeColor = System::Drawing::SystemColors::GrayText;		
		tempRightNumbers->Location = System::Drawing::Point(400, offset + 45);
		tempRightNumbers->SelectionMode = System::Windows::Forms::SelectionMode::None;
		tempRightNumbers->Size = System::Drawing::Size(22, 21 * listSize);
		tempRightNumbers->RightToLeft = System::Windows::Forms::RightToLeft::Yes;

		tempRightNumbers->DataSource = musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->GetRange(listSize, musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->Count - listSize);
		tempRightNumbers->DisplayMember = "SongNumber";

		panel2->Controls->Add(tempRightNumbers);
		rightNumbers->Add(tempRightNumbers);

		//
		// left songs
		//
		System::Windows::Forms::ListBox^ tempLeftSongs = (gcnew System::Windows::Forms::ListBox());
		if (musicPlayer->getSmartPlay() == false)
			tempLeftSongs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
		else
			tempLeftSongs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
		tempLeftSongs->BorderStyle = System::Windows::Forms::BorderStyle::None;
		tempLeftSongs->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));		
		tempLeftSongs->Location = System::Drawing::Point(180, offset + 45);
		tempLeftSongs->Size = System::Drawing::Size(210, 21 * listSize);
		tempLeftSongs->SelectedIndexChanged += gcnew System::EventHandler(this, &PlayerForm::songs_SelectedIndexChanged);
		tempLeftSongs->DoubleClick += gcnew System::EventHandler(this, &PlayerForm::songs_DoubleClick);

		tempLeftSongs->DataSource = musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->GetRange(0, listSize);
		tempLeftSongs->DisplayMember = "SongName";

		panel2->Controls->Add(tempLeftSongs);
		songSelectionChanged = false;
		tempLeftSongs->ClearSelected();
		songSelectionChanged = true;
		leftSongs->Add(tempLeftSongs);
				
		//
		// right songs
		//
		System::Windows::Forms::ListBox^ tempRightSongs = (gcnew System::Windows::Forms::ListBox());
		if (musicPlayer->getSmartPlay() == false)
			tempRightSongs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
		else
			tempRightSongs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
		tempRightSongs->BorderStyle = System::Windows::Forms::BorderStyle::None;
		tempRightSongs->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));		
		tempRightSongs->Location = System::Drawing::Point(428, offset + 45);
		if (i != musicPlayer->getSelectedArtist()->getAlbums()->Count - 1)
			tempRightSongs->Size = System::Drawing::Size(210, 21 * listSize);
		// in the case that it is the last song list and has a list size that is smaller than the music artwork
		else if (listSize < 7)
			tempRightSongs->Size = System::Drawing::Size(210, 21 * 7 + 75);
		else
			tempRightSongs->Size = System::Drawing::Size(210, 21 * listSize + 75);
		tempRightSongs->SelectedIndexChanged += gcnew System::EventHandler(this, &PlayerForm::songs_SelectedIndexChanged);
		tempRightSongs->DoubleClick += gcnew System::EventHandler(this, &PlayerForm::songs_DoubleClick);

		tempRightSongs->DataSource = musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->GetRange(listSize, musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->Count - listSize);
		tempRightSongs->DisplayMember = "SongName";		

		panel2->Controls->Add(tempRightSongs);
		songSelectionChanged = false;
		tempRightSongs->ClearSelected();
		songSelectionChanged = true;
		rightSongs->Add(tempRightSongs);		

		//
		// year
		//
		System::Windows::Forms::Label^ tempYear = (gcnew System::Windows::Forms::Label());
		tempYear->AutoSize = true;
		tempYear->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		tempYear->Location = System::Drawing::Point(0, offset + 158);

		if (musicPlayer->getSelectedArtist()->getAlbums()[i]->getYear() <= 0)
			tempYear->Text = "(unknown year)";
		else
			tempYear->Text = System::Convert::ToString(musicPlayer->getSelectedArtist()->getAlbums()[i]->getYear());

		panel2->Controls->Add(tempYear);
		year->Add(tempYear);

		//
		// genre
		//
		System::Windows::Forms::Label^ tempGenre = (gcnew System::Windows::Forms::Label());
		tempGenre->AutoSize = true;
		tempGenre->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));
		tempGenre->Location = System::Drawing::Point(0, offset + 173);

		if (String::IsNullOrWhiteSpace(musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()[0]->getGenre()))
			tempGenre->Text = "(unknown genre)";
		else
			tempGenre->Text = musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()[0]->getGenre();

		panel2->Controls->Add(tempGenre);
		genre->Add(tempGenre);
		
		// adjusting offset
		if (listSize < 7)
			offset = tempGenre->Location.Y + tempGenre->Size.Height + 45;
		else
			offset = tempRightSongs->Location.Y + tempRightSongs->Size.Height + 45;			
	}	
}

System::Void PlayerForm::songs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (songSelectionChanged == true) {
		int index = -1;
		int list = -1;
		
		if (selectedList != nullptr && selectedList != (ListBox^)sender) {
			songSelectionChanged = false;
			selectedList->ClearSelected();
			selectedList->ClearSelected();
			songSelectionChanged = true;
		}
		selectedList = (ListBox^)sender;
		
		for (int i = 0; i < leftSongs->Count; i++) {
			if (leftSongs[i]->SelectedIndex != -1) {
				index = leftSongs[i]->SelectedIndex;
				list = i * 2;
			}
			else if (rightSongs[i]->SelectedIndex != -1) {
				index = rightSongs[i]->SelectedIndex;
				list = i * 2 + 1;
			}
		}

		// setting selected song
		// this will get affected by the size of the text in the song lists
		if (list%2 == 0)
			musicPlayer->setSelectedSong(musicPlayer->getSelectedArtist()->getAlbums()[list / 2]->getSongs()[index]);
		else if (list%2 == 1)
			musicPlayer->setSelectedSong(musicPlayer->getSelectedArtist()->getAlbums()[(list-1) / 2]->getSongs()[index + leftSongs[(list-1) / 2]->Size.Height/21]);
		
		if (musicPlayer->getCurrentSong() == nullptr)
			musicPlayer->setCurrentSong();
		
	}
}

System::Void PlayerForm::songs_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	musicPlayer->setCurrentSong();
	if (musicPlayer->getSmartPlay() == false)
		playSongNormal();
	else
		playSongSmart();
}

System::Void PlayerForm::artists_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	musicPlayer->setCurrentArtist();
	if (musicPlayer->getSmartPlay() == false)
		playSongNormal();
	else
		playSongSmart();
}

//Needed in order to change the play button to pause when playing a song
void PlayerForm::playSongNormal() {
	if (backgroundWorker1->IsBusy == false)
		backgroundWorker1->RunWorkerAsync(1);
	roundButton->BackgroundImage = imageList1->Images[1];
	musicPlayer->playSong();
	// matching song volume to volume bar
	if (musicPlayer->isMP3(musicPlayer->getCurrentSong()))
		musicPlayer->getNAudio()->Volume = volume->Value / 100.0;
	else
		musicPlayer->getSFML()->setVolume(volume->Value);

	play = true;
}

//Needed in order to change the pause button back into a play button
void PlayerForm::pauseSongNormal() {
	roundButton->BackgroundImage = imageList1->Images[0];
	musicPlayer->pauseSong();
	play = false;
}

void PlayerForm::playSongSmart() {
	if (backgroundWorker1->IsBusy == false)
		backgroundWorker1->RunWorkerAsync(1);
	roundButton->BackgroundImage = imageList1->Images[3];
	musicPlayer->playSong();
	// matching song volume to volume bar
	if (musicPlayer->isMP3(musicPlayer->getCurrentSong()))
		musicPlayer->getNAudio()->Volume = volume->Value / 100;
	else
		musicPlayer->getSFML()->setVolume(volume->Value);

	play = true;
}

void PlayerForm::pauseSongSmart() {
	roundButton->BackgroundImage = imageList1->Images[2];
	musicPlayer->pauseSong();
	play = false;
}

System::Void PlayerForm::backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e) {
	while (true)
	{
		// if (progressBar1->Value == progressBar1->Maximum) 			
		backgroundWorker1->ReportProgress(1);  
		System::Threading::Thread::Sleep(1);   
	}
}

System::Void PlayerForm::backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e) {
	//progressBar1->Value += e->ProgressPercentage;
	if (musicPlayer->isMP3(musicPlayer->getCurrentSong())) {
		progressBar1->Value = 100000 * musicPlayer->getNAudioReader()->CurrentTime.TotalSeconds / musicPlayer->getNAudioReader()->TotalTime.TotalSeconds;
		if (progressBar1->Value == progressBar1->Maximum)
			musicPlayer->playNextSong();
	}
	else {
		progressBar1->Value = 100000 * musicPlayer->getSFML()->getPlayingOffset().asSeconds() / musicPlayer->getSFML()->getDuration().asSeconds() + offsetSFML;
		if (progressBar1->Value > 99900)
			musicPlayer->playNextSong();
	}

	if (musicPlayer->getSFML()->getPlayingOffset().asSeconds() == 0)
		offsetSFML = 0;
} 

System::Void PlayerForm::progressBar1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (musicPlayer->getCurrentSong() != nullptr) {
		if (musicPlayer->isMP3(musicPlayer->getCurrentSong()))
			musicPlayer->getNAudioReader()->Skip((e->Location.X / 960.0) * musicPlayer->getNAudioReader()->TotalTime.TotalSeconds - musicPlayer->getNAudioReader()->CurrentTime.TotalSeconds);
		else {
			musicPlayer->getSFML()->setPlayingOffset(sf::microseconds((e->Location.X / 960.0) * musicPlayer->getSFML()->getDuration().asMicroseconds() / 2));
			offsetSFML = 100000 * (e->Location.X / 960.0) / 2;
		}
	}
	mouseDownProgress = true;
}

System::Void PlayerForm::progressBar1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (mouseDownProgress == true) {
		if (musicPlayer->getCurrentSong() != nullptr) {
			if (musicPlayer->isMP3(musicPlayer->getCurrentSong())) {
				if (e->Location.X > 960)
					musicPlayer->getNAudioReader()->Skip(musicPlayer->getNAudioReader()->TotalTime.TotalSeconds - musicPlayer->getNAudioReader()->CurrentTime.TotalSeconds);
				else if (e->Location.X < 0)
					musicPlayer->getNAudioReader()->Skip(-musicPlayer->getNAudioReader()->CurrentTime.TotalSeconds);
				else
					musicPlayer->getNAudioReader()->Skip((e->Location.X / 960.0) * musicPlayer->getNAudioReader()->TotalTime.TotalSeconds - musicPlayer->getNAudioReader()->CurrentTime.TotalSeconds);
			}
			else {
				if (e->Location.X > 960) {
					musicPlayer->getSFML()->setPlayingOffset(sf::microseconds(musicPlayer->getSFML()->getDuration().asMicroseconds() / 2));
					offsetSFML = 50000;
				}
				else if (e->Location.X < 0) {
					musicPlayer->getSFML()->setPlayingOffset(sf::microseconds(0));
					offsetSFML = 0;
				}
				else {
					musicPlayer->getSFML()->setPlayingOffset(sf::microseconds((e->Location.X / 960.0) * musicPlayer->getSFML()->getDuration().asMicroseconds() / 2));
					offsetSFML = 100000 * (e->Location.X / 960.0) / 2;
				}
			}
		}
	}
}

System::Void PlayerForm::progressBar1_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	mouseDownProgress = false;
}

System::Void PlayerForm::button2_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	Form^ prefWindow = gcnew PreferencesForm(musicPlayer);
	prefWindow->Show();
}

System::Void PlayerForm::volume_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	volume->Value = 100 * (e->Location.X / 105.0);
	if (musicPlayer->getCurrentSong() != nullptr) {
		if (musicPlayer->isMP3(musicPlayer->getCurrentSong()))
			musicPlayer->getNAudio()->Volume = volume->Value / 100.0;
		else
			musicPlayer->getSFML()->setVolume(volume->Value);
	}
	mouseDownVolume = true;
}

System::Void PlayerForm::volume_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	if (mouseDownVolume == true) {
		if (e->Location.X > 105) 
			volume->Value = 100;
		else if (e->Location.X < 0)
			volume->Value = 0;
		else
			volume->Value = 100 * (e->Location.X / 105.0);
		// setting song volume
		if (musicPlayer->getCurrentSong() != nullptr) {
			if (musicPlayer->isMP3(musicPlayer->getCurrentSong()))
				musicPlayer->getNAudio()->Volume = volume->Value / 100.0;
			else
				musicPlayer->getSFML()->setVolume(volume->Value);
		}
	}
}

System::Void PlayerForm::volume_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	mouseDownVolume = false;
}

