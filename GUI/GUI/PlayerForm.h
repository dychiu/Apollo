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
		System::Windows::Forms::PictureBox^  pictureBox1;
		System::Windows::Forms::ListBox^  listBox2;
		System::Windows::Forms::Label^  label1;
		System::Windows::Forms::ListBox^  listBox3;
		System::Windows::Forms::ListBox^  listBox5;
		System::Windows::Forms::ListBox^  listBox4;
		System::Windows::Forms::ListBox^  listBox6;
		System::Windows::Forms::ListBox^  listBox7;
		System::Windows::Forms::ListBox^  listBox8;
		System::Windows::Forms::ListBox^  listBox9;
		System::Windows::Forms::Label^  label2;
		System::Windows::Forms::PictureBox^  pictureBox2;
		System::Windows::Forms::ListBox^  listBox10;
		System::Windows::Forms::ListBox^  listBox11;
		System::Windows::Forms::ListBox^  listBox12;
		System::Windows::Forms::ListBox^  listBox13;
		System::Windows::Forms::Label^  label3;
		System::Windows::Forms::PictureBox^  pictureBox3;
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
		bool smartPlayMode;
		MusicPlayer^ musicPlayer;

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

		// changes normal mode to smart mode
		void changeToSmart();
		// changes smart mode to normal mode
		void changeToNormal();	

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
			this->listBox10 = (gcnew System::Windows::Forms::ListBox());
			this->listBox11 = (gcnew System::Windows::Forms::ListBox());
			this->listBox12 = (gcnew System::Windows::Forms::ListBox());
			this->listBox13 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox6 = (gcnew System::Windows::Forms::ListBox());
			this->listBox7 = (gcnew System::Windows::Forms::ListBox());
			this->listBox8 = (gcnew System::Windows::Forms::ListBox());
			this->listBox9 = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->listBox3 = (gcnew System::Windows::Forms::ListBox());
			this->listBox5 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox4 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->roundButton = (gcnew System::Windows::Forms::Button());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->skipButton = (gcnew System::Windows::Forms::Button());
			this->smartPlayButton = (gcnew System::Windows::Forms::Button());
			this->minimizeButton = (gcnew System::Windows::Forms::Button());
			this->notifyIcon1 = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->importButton = (gcnew System::Windows::Forms::Button());
			this->volume = (gcnew System::Windows::Forms::ProgressBar());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(27) {
				L"A Day To Remember", L"The All-American Rejects",
					L"Arcade Fire", L"Awolnation", L"Bastille", L"Billy Talent", L"Blink 182", L"Bowling For Soup", L"Cage the Elephant ", L"Down With Webster",
					L"Ed Sheeran", L"Faber Drive", L"Fall Out Boy ", L"Foster the People", L"Fountains of Wayne", L"Artist Test", L"Artist Test",
					L"Artist Test", L"Artist Test", L"Artist Test", L"Artist Test", L"Artist Test", L"Artist Test", L"Artist Test", L"Artist Test",
					L"Artist Test", L"Artist Test"
			});
			this->listBox1->Location = System::Drawing::Point(0, 21);
			this->listBox1->Name = L"listBox1";
			this->listBox1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->listBox1->Size = System::Drawing::Size(376, 621);
			this->listBox1->TabIndex = 1;
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->progressBar1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->progressBar1->Location = System::Drawing::Point(-1, 640);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(1282, 81);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 2;
			this->progressBar1->Value = 25;
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
			this->panel2->Controls->Add(this->listBox10);
			this->panel2->Controls->Add(this->listBox11);
			this->panel2->Controls->Add(this->listBox12);
			this->panel2->Controls->Add(this->listBox13);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->pictureBox3);
			this->panel2->Controls->Add(this->listBox6);
			this->panel2->Controls->Add(this->listBox7);
			this->panel2->Controls->Add(this->listBox8);
			this->panel2->Controls->Add(this->listBox9);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Controls->Add(this->listBox3);
			this->panel2->Controls->Add(this->listBox5);
			this->panel2->Controls->Add(this->listBox2);
			this->panel2->Controls->Add(this->listBox4);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Location = System::Drawing::Point(373, 21);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(930, 621);
			this->panel2->TabIndex = 4;
			// 
			// listBox10
			// 
			this->listBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox10->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox10->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox10->FormattingEnabled = true;
			this->listBox10->ItemHeight = 27;
			this->listBox10->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Go", L"Asthenia", L"Always", L"Easy Target",
					L"All of This", L"Here\'s Your Letter", L"I\'m Lost Without You"
			});
			this->listBox10->Location = System::Drawing::Point(573, 603);
			this->listBox10->Name = L"listBox10";
			this->listBox10->Size = System::Drawing::Size(261, 243);
			this->listBox10->TabIndex = 15;
			// 
			// listBox11
			// 
			this->listBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox11->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox11->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox11->ForeColor = System::Drawing::SystemColors::GrayText;
			this->listBox11->FormattingEnabled = true;
			this->listBox11->ItemHeight = 27;
			this->listBox11->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"8", L"9", L"10", L"11", L"12", L"13", L"14" });
			this->listBox11->Location = System::Drawing::Point(531, 603);
			this->listBox11->Name = L"listBox11";
			this->listBox11->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox11->Size = System::Drawing::Size(47, 243);
			this->listBox11->TabIndex = 17;
			// 
			// listBox12
			// 
			this->listBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox12->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox12->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox12->FormattingEnabled = true;
			this->listBox12->ItemHeight = 27;
			this->listBox12->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Feeling This", L"Obvious", L"I Miss You", L"Violence",
					L"Stockholm Syndrome", L"Down", L"The Fallen Interlude"
			});
			this->listBox12->Location = System::Drawing::Point(246, 603);
			this->listBox12->Name = L"listBox12";
			this->listBox12->Size = System::Drawing::Size(261, 243);
			this->listBox12->TabIndex = 13;
			// 
			// listBox13
			// 
			this->listBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox13->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox13->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox13->ForeColor = System::Drawing::SystemColors::GrayText;
			this->listBox13->FormattingEnabled = true;
			this->listBox13->ItemHeight = 27;
			this->listBox13->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"1", L"2", L"3", L"4", L"5", L"6", L"7" });
			this->listBox13->Location = System::Drawing::Point(216, 603);
			this->listBox13->Name = L"listBox13";
			this->listBox13->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox13->Size = System::Drawing::Size(47, 243);
			this->listBox13->TabIndex = 16;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(209, 557);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(243, 37);
			this->label3->TabIndex = 14;
			this->label3->Text = L"Neighborhoods";
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox3->ImageLocation = L"C:\\Users\\Dylan\\Music\\Blink 182\\(2011) Neighborhoods\\Album Artwork.png";
			this->pictureBox3->Location = System::Drawing::Point(0, 552);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(200, 200);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 12;
			this->pictureBox3->TabStop = false;
			// 
			// listBox6
			// 
			this->listBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox6->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox6->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox6->FormattingEnabled = true;
			this->listBox6->ItemHeight = 27;
			this->listBox6->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Go", L"Asthenia", L"Always", L"Easy Target", L"All of This",
					L"Here\'s Your Letter", L"I\'m Lost Without You"
			});
			this->listBox6->Location = System::Drawing::Point(573, 331);
			this->listBox6->Name = L"listBox6";
			this->listBox6->Size = System::Drawing::Size(261, 243);
			this->listBox6->TabIndex = 9;
			// 
			// listBox7
			// 
			this->listBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox7->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox7->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox7->ForeColor = System::Drawing::SystemColors::GrayText;
			this->listBox7->FormattingEnabled = true;
			this->listBox7->ItemHeight = 27;
			this->listBox7->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"8", L"9", L"10", L"11", L"12", L"13", L"14" });
			this->listBox7->Location = System::Drawing::Point(531, 331);
			this->listBox7->Name = L"listBox7";
			this->listBox7->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox7->Size = System::Drawing::Size(47, 243);
			this->listBox7->TabIndex = 11;
			// 
			// listBox8
			// 
			this->listBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox8->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox8->FormattingEnabled = true;
			this->listBox8->ItemHeight = 27;
			this->listBox8->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Feeling This", L"Obvious", L"I Miss You", L"Violence",
					L"Stockholm Syndrome", L"Down", L"The Fallen Interlude"
			});
			this->listBox8->Location = System::Drawing::Point(246, 331);
			this->listBox8->Name = L"listBox8";
			this->listBox8->Size = System::Drawing::Size(261, 243);
			this->listBox8->TabIndex = 7;
			// 
			// listBox9
			// 
			this->listBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox9->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox9->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox9->ForeColor = System::Drawing::SystemColors::GrayText;
			this->listBox9->FormattingEnabled = true;
			this->listBox9->ItemHeight = 27;
			this->listBox9->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"1", L"2", L"3", L"4", L"5", L"6", L"7" });
			this->listBox9->Location = System::Drawing::Point(216, 331);
			this->listBox9->Name = L"listBox9";
			this->listBox9->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox9->Size = System::Drawing::Size(47, 243);
			this->listBox9->TabIndex = 10;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(209, 285);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(467, 37);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Take Off Your Pants and Jacket";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox2->ImageLocation = L"C:\\Users\\Dylan\\Music\\Blink 182\\(2001) Take Off Your Pants And Jacket\\albumart.png"
				L"";
			this->pictureBox2->Location = System::Drawing::Point(0, 280);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(200, 200);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// listBox3
			// 
			this->listBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox3->FormattingEnabled = true;
			this->listBox3->ItemHeight = 27;
			this->listBox3->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Go", L"Asthenia", L"Always", L"Easy Target", L"All of This",
					L"Here\'s Your Letter", L"I\'m Lost Without You"
			});
			this->listBox3->Location = System::Drawing::Point(573, 60);
			this->listBox3->Name = L"listBox3";
			this->listBox3->Size = System::Drawing::Size(261, 243);
			this->listBox3->TabIndex = 3;
			// 
			// listBox5
			// 
			this->listBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox5->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox5->ForeColor = System::Drawing::SystemColors::GrayText;
			this->listBox5->FormattingEnabled = true;
			this->listBox5->ItemHeight = 27;
			this->listBox5->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"8", L"9", L"10", L"11", L"12", L"13", L"14" });
			this->listBox5->Location = System::Drawing::Point(531, 60);
			this->listBox5->Name = L"listBox5";
			this->listBox5->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox5->Size = System::Drawing::Size(47, 243);
			this->listBox5->TabIndex = 5;
			// 
			// listBox2
			// 
			this->listBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 27;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Feeling This", L"Obvious", L"I Miss You", L"Violence",
					L"Stockholm Syndrome", L"Down", L"The Fallen Interlude"
			});
			this->listBox2->Location = System::Drawing::Point(246, 60);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(261, 243);
			this->listBox2->TabIndex = 1;
			// 
			// listBox4
			// 
			this->listBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->listBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox4->ForeColor = System::Drawing::SystemColors::GrayText;
			this->listBox4->FormattingEnabled = true;
			this->listBox4->ItemHeight = 27;
			this->listBox4->Items->AddRange(gcnew cli::array< System::Object^  >(7) { L"1", L"2", L"3", L"4", L"5", L"6", L"7" });
			this->listBox4->Location = System::Drawing::Point(216, 60);
			this->listBox4->Name = L"listBox4";
			this->listBox4->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listBox4->Size = System::Drawing::Size(47, 243);
			this->listBox4->TabIndex = 4;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(209, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 37);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Blink 182";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->ImageLocation = L"C:\\Users\\Dylan\\Music\\Blink 182\\(2003) Blink 182\\albumart.jpg";
			this->pictureBox1->Location = System::Drawing::Point(0, 9);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(200, 200);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
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
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
		}

		#pragma endregion
	
	};
}
