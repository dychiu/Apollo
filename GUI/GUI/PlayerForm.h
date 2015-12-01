#pragma once

#include "src/MusicPlayer.h"

ref class MusicPlayer;

namespace GUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	public ref class PlayerForm : public System::Windows::Forms::Form {
	public:
		PlayerForm();

		const int WM_NCLBUTTONDOWN = 0xA1;
	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;

	public:

		const int HT_CAPTION = 0x2;
		[DllImportAttribute("user32.dll")]
		static int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);
		[DllImportAttribute("user32.dll")]
		static bool ReleaseCapture();

	private: 
		System::Windows::Forms::ListBox^  listBox1;
		System::Windows::Forms::ProgressBar^  progressBar1;
		System::Windows::Forms::Panel^  panel1;
		System::Windows::Forms::Panel^  panel2;
		System::Windows::Forms::Button^  roundButton;
		System::Windows::Forms::ImageList^  imageList1;
		System::Windows::Forms::Button^  skipButton;
		System::Windows::Forms::Button^  smartPlayButton;
		System::Windows::Forms::Button^  minimizeButton;
		System::Windows::Forms::NotifyIcon^  notifyIcon1;
		System::Windows::Forms::Button^  importButton;
		System::Windows::Forms::ProgressBar^  volume;
		System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;
		System::Windows::Forms::Button^  button1;
		System::ComponentModel::IContainer^  components;
	
		bool play;
		bool artistSelectionsCleared;
		bool songSelectionChanged;
		MusicPlayer^ musicPlayer;
		Generic::List<PictureBox^>^ artwork;
		Generic::List<Label^>^ album;
		Generic::List<ListBox^>^ leftNumbers;
		Generic::List<ListBox^>^ rightNumbers;
		Generic::List<ListBox^>^ leftSongs;
		Generic::List<ListBox^>^ rightSongs;
		System::Windows::Forms::ListBox^ selectedList;

		// closes window
		System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
		// moves window around by dragging on top bar
		System::Void PlayerForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		// creates circle button for play button
		System::Void roundButton_Paint(Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
		// play button click
		System::Void roundButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		// creates cirlce button for smart play button
		System::Void smartPlayButton_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
		// smart play button click
		System::Void smartPlayButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		// creates circle button for skip button
		System::Void skipButton_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
		// skip button click
		System::Void skipButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		// minimizes window
		System::Void minimizeButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		// opens folder browser dialog when clicking import button
		System::Void importButton_Release(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
		// selection change in artist list
		System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void songs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		System::Void songs_DoubleClick(System::Object^  sender, System::EventArgs^  e);
		System::Void artists_DoubleClick(System::Object^  sender, System::EventArgs^  e);
		System::Void backgroundWorker1_DoWork(System::Object^  sender, System::ComponentModel::DoWorkEventArgs^  e);
		System::Void backgroundWorker1_ProgressChanged(System::Object^  sender, System::ComponentModel::ProgressChangedEventArgs^  e);
		
		//plays a song (for button change)
		void playSongNormal();
		void playSongSmart();
		//pauses a song (for button change)
		void pauseSongNormal();
		void pauseSongSmart();
		// changes normal mode to smart mode
		void changeToSmart();
		// changes smart mode to normal mode
		void changeToNormal();	
		// displays the albums and songs for the selected artist
		void changeArtist();
		void removeComponents();
		void createComponents();

		#pragma region Windows Form Designer generated code
		
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PlayerForm::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->roundButton = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->skipButton = (gcnew System::Windows::Forms::Button());
			this->smartPlayButton = (gcnew System::Windows::Forms::Button());
			this->minimizeButton = (gcnew System::Windows::Forms::Button());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->importButton = (gcnew System::Windows::Forms::Button());
			this->volume = (gcnew System::Windows::Forms::ProgressBar());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(1259, 1);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(18, 18);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PlayerForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::Color::White;
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->ForeColor = System::Drawing::Color::Black;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->IntegralHeight = false;
			this->listBox1->ItemHeight = 37;
			this->listBox1->Location = System::Drawing::Point(0, 21);
			this->listBox1->Name = L"listBox1";
			this->listBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBox1->Size = System::Drawing::Size(376, 621);
			this->listBox1->TabIndex = 1;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &PlayerForm::listBox1_SelectedIndexChanged);
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &PlayerForm::artists_DoubleClick);
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->progressBar1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->progressBar1->Location = System::Drawing::Point(-1, 640);
			this->progressBar1->Maximum = 100000;
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1282, 81);
			this->progressBar1->Step = 1;
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 2;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel1->Location = System::Drawing::Point(355, 21);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(21, 621);
			this->panel1->TabIndex = 3;
			// 
			// panel2
			// 
			this->panel2->AutoScroll = true;
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->panel2->Location = System::Drawing::Point(373, 21);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(930, 621);
			this->panel2->TabIndex = 4;
			// 
			// roundButton
			// 
			this->roundButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->roundButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"roundButton.BackgroundImage")));
			this->roundButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->roundButton->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->roundButton->FlatAppearance->BorderSize = 0;
			this->roundButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->roundButton->Location = System::Drawing::Point(581, 587);
			this->roundButton->Name = L"roundButton";
			this->roundButton->Size = System::Drawing::Size(115, 106);
			this->roundButton->TabIndex = 19;
			this->roundButton->UseVisualStyleBackColor = false;
			this->roundButton->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PlayerForm::roundButton_Paint);
			this->roundButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PlayerForm::roundButton_Release);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"playbutton.jpg");
			this->imageList1->Images->SetKeyName(1, L"pausebutton.jpg");
			this->imageList1->Images->SetKeyName(2, L"smartplay.jpg");
			this->imageList1->Images->SetKeyName(3, L"smartplaypause.jpg");
			this->imageList1->Images->SetKeyName(4, L"skip.jpg");
			this->imageList1->Images->SetKeyName(5, L"smartplayskip.jpg");
			this->imageList1->Images->SetKeyName(6, L"closeblue.jpg");
			this->imageList1->Images->SetKeyName(7, L"closered.jpg");
			this->imageList1->Images->SetKeyName(8, L"minimizeblue.jpg");
			this->imageList1->Images->SetKeyName(9, L"minimizered.jpg");
			this->imageList1->Images->SetKeyName(10, L"importblue.jpg");
			this->imageList1->Images->SetKeyName(11, L"importred.jpg");
			this->imageList1->Images->SetKeyName(12, L"default.png");
			this->imageList1->Images->SetKeyName(13, L"play.png");
			// 
			// skipButton
			// 
			this->skipButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"skipButton.BackgroundImage")));
			this->skipButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->skipButton->FlatAppearance->BorderSize = 0;
			this->skipButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->skipButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->skipButton->Location = System::Drawing::Point(713, 608);
			this->skipButton->Name = L"skipButton";
			this->skipButton->Size = System::Drawing::Size(70, 65);
			this->skipButton->TabIndex = 22;
			this->skipButton->UseVisualStyleBackColor = true;
			this->skipButton->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PlayerForm::skipButton_Paint);
			this->skipButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PlayerForm::skipButton_Release);
			// 
			// smartPlayButton
			// 
			this->smartPlayButton->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->smartPlayButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"smartPlayButton.BackgroundImage")));
			this->smartPlayButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->smartPlayButton->FlatAppearance->BorderSize = 0;
			this->smartPlayButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->smartPlayButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->smartPlayButton->Location = System::Drawing::Point(526, 604);
			this->smartPlayButton->Name = L"smartPlayButton";
			this->smartPlayButton->Size = System::Drawing::Size(70, 66);
			this->smartPlayButton->TabIndex = 23;
			this->smartPlayButton->UseVisualStyleBackColor = false;
			this->smartPlayButton->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &PlayerForm::smartPlayButton_Paint);
			this->smartPlayButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PlayerForm::smartPlayButton_Release);
			// 
			// minimizeButton
			// 
			this->minimizeButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minimizeButton.BackgroundImage")));
			this->minimizeButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->minimizeButton->FlatAppearance->BorderSize = 0;
			this->minimizeButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->minimizeButton->Location = System::Drawing::Point(1238, 1);
			this->minimizeButton->Name = L"minimizeButton";
			this->minimizeButton->Size = System::Drawing::Size(18, 18);
			this->minimizeButton->TabIndex = 24;
			this->minimizeButton->UseVisualStyleBackColor = true;
			this->minimizeButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PlayerForm::minimizeButton_Release);
			// 
			// notifyIcon1
			// 
			this->notifyIcon1->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"notifyIcon1.Icon")));
			this->notifyIcon1->Text = L"notifyIcon1";
			// 
			// importButton
			// 
			this->importButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"importButton.BackgroundImage")));
			this->importButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->importButton->FlatAppearance->BorderSize = 0;
			this->importButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->importButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->importButton->Location = System::Drawing::Point(1242, 628);
			this->importButton->Name = L"importButton";
			this->importButton->Size = System::Drawing::Size(25, 25);
			this->importButton->TabIndex = 25;
			this->importButton->UseVisualStyleBackColor = true;
			this->importButton->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &PlayerForm::importButton_Release);
			// 
			// volume
			// 
			this->volume->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)));
			this->volume->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->volume->Location = System::Drawing::Point(1091, 629);
			this->volume->Name = L"volume";
			this->volume->Size = System::Drawing::Size(144, 22);
			this->volume->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->volume->TabIndex = 26;
			this->volume->Value = 50;
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->Description = L"Please select a directory to import all of the songs within it.  ";
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &PlayerForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &PlayerForm::backgroundWorker1_ProgressChanged);
			// 
			// PlayerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->volume);
			this->Controls->Add(this->importButton);
			this->Controls->Add(this->minimizeButton);
			this->Controls->Add(this->roundButton);
			this->Controls->Add(this->smartPlayButton);
			this->Controls->Add(this->skipButton);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->listBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"PlayerForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"PlayerForm";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PlayerForm::PlayerForm_MouseDown);
			this->ResumeLayout(false);

		}

		#pragma endregion
		
	};
}
