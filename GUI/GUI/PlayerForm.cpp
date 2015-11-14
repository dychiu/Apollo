#include "PlayerForm.h"
#include "boost/filesystem.hpp"

using namespace GUI;

PlayerForm::PlayerForm() {
	boost::filesystem::path test;
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
		}
		else if (play == true) {
			roundButton->BackgroundImage = imageList1->Images[0];
			play = false;
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
	;
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

	listBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
	listBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
		static_cast<System::Int32>(static_cast<System::Byte>(210)));
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

	listBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox11->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox12->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
	listBox13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(210)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
		static_cast<System::Int32>(static_cast<System::Byte>(255)));
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
}