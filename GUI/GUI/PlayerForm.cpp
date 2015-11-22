#include "PlayerForm.h"

using namespace GUI;

PlayerForm::PlayerForm() {
	InitializeComponent();
	// initialize play button image
	roundButton->BackgroundImage = imageList1->Images[0];
	play = false;
	// initialize smart play button image
	smartPlayButton->BackgroundImage = imageList1->Images[2];
	smartPlayMode = false;
	// initialize skip button image
	skipButton->BackgroundImage = imageList1->Images[4];
	// initialize close button image
	button1->BackgroundImage = imageList1->Images[6];
	// initialize minimiaze button image
	minimizeButton->BackgroundImage = imageList1->Images[8];
	// initialize import button image
	importButton->BackgroundImage = imageList1->Images[10];

	musicPlayer = gcnew MusicPlayer();
	
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
	if (smartPlayMode == false) {
		if (play == false) {
			roundButton->BackgroundImage = imageList1->Images[1];
			play = true;
			musicPlayer->playSong();
		}
		else if (play == true) {
			roundButton->BackgroundImage = imageList1->Images[0];
			play = false;
			musicPlayer->pauseSong();
		}
	}
	else if (smartPlayMode == true) {
		if (play == false) {
			roundButton->BackgroundImage = imageList1->Images[3];
			play = true;
		}
		else if (play == true) {
			roundButton->BackgroundImage = imageList1->Images[2];
			play = false;
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
	if (smartPlayMode == false) {
		changeToSmart();
		smartPlayMode = true;
		play = false;
	}
	else if (smartPlayMode == true) {
		changeToNormal();
		smartPlayMode = false;
		play = false;
	}
}

void PlayerForm::changeToSmart() {
	roundButton->BackgroundImage = imageList1->Images[2];
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
	this->importButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
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
	roundButton->BackgroundImage = imageList1->Images[0];
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
	this->importButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
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
	// put stuff in here
}

System::Void PlayerForm::minimizeButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	this->WindowState = FormWindowState::Minimized;
}

System::Void PlayerForm::importButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	folderBrowserDialog1->ShowDialog();
	musicPlayer->getMusicLibrary()->import(folderBrowserDialog1->SelectedPath);
	listBox1->DataSource = nullptr;
	listBox1->DataSource = musicPlayer->getMusicLibrary()->getArtistList();
	listBox1->DisplayMember = "ArtistName";
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
	}
	artwork->Clear();
	album->Clear();
	leftNumbers->Clear();
	rightNumbers->Clear();
	leftSongs->Clear();
	rightSongs->Clear();
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
		
		/*
		if ()
		tempArtwork->ImageLocation = musicPlayer->getSelectedArtist()->getAlbums()[i]->urlLocation;
		else
		*/
		tempArtwork->Image = imageList1->Images[12];

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
		if (smartPlayMode == false)
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

		for (int j = 0; j < listSize; j++)
			tempLeftNumbers->Items->Add(j + 1);

		panel2->Controls->Add(tempLeftNumbers);
		leftNumbers->Add(tempLeftNumbers);

		//
		// right track numbers
		//
		System::Windows::Forms::ListBox^ tempRightNumbers = (gcnew System::Windows::Forms::ListBox());
		if (smartPlayMode == false)
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

		for (int j = 0; j < musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->Count - listSize; j++)
			tempRightNumbers->Items->Add(j + listSize + 1);

		panel2->Controls->Add(tempRightNumbers);
		rightNumbers->Add(tempRightNumbers);

		//
		// left songs
		//
		System::Windows::Forms::ListBox^ tempLeftSongs = (gcnew System::Windows::Forms::ListBox());
		if (smartPlayMode == false)
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
		
		tempLeftSongs->DataSource = musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->GetRange(0, listSize);
		tempLeftSongs->DisplayMember = "SongName";

		panel2->Controls->Add(tempLeftSongs);
		tempLeftSongs->ClearSelected();
		leftSongs->Add(tempLeftSongs);
				
		//
		// right songs
		//
		System::Windows::Forms::ListBox^ tempRightSongs = (gcnew System::Windows::Forms::ListBox());
		if (smartPlayMode == false)
			tempRightSongs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
		else
			tempRightSongs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
		tempRightSongs->BorderStyle = System::Windows::Forms::BorderStyle::None;
		tempRightSongs->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(0)));		
		tempRightSongs->Location = System::Drawing::Point(428, offset + 45);
		if (i != musicPlayer->getSelectedArtist()->getAlbums()->Count-1)
			tempRightSongs->Size = System::Drawing::Size(210, 21 * listSize);
		else
			tempRightSongs->Size = System::Drawing::Size(210, 21 * listSize + 75);
		tempRightSongs->SelectedIndexChanged += gcnew System::EventHandler(this, &PlayerForm::songs_SelectedIndexChanged);
		
		tempRightSongs->DataSource = musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->GetRange(listSize, musicPlayer->getSelectedArtist()->getAlbums()[i]->getSongs()->Count - listSize);
		tempRightSongs->DisplayMember = "SongName";		

		panel2->Controls->Add(tempRightSongs);
		tempRightSongs->ClearSelected();
		rightSongs->Add(tempRightSongs);		
					
		offset = tempRightSongs->Location.Y + tempRightSongs->Size.Height + 45;
	}	
}

System::Void PlayerForm::songs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (songSelectionChanged == true) {
		for (int i = 0; i < leftSongs->Count; i++) {
			if (leftSongs[i] != sender) {
				songSelectionChanged = false;
				leftSongs[i]->ClearSelected();				
			}
		}
		for (int i = 0; i < rightSongs->Count; i++) {
			if (rightSongs[i] != sender) {
				songSelectionChanged = false;
				rightSongs[i]->ClearSelected();				
			}
		}		
	}
	songSelectionChanged = true;
}

