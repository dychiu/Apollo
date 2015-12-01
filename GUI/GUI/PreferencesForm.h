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
	using namespace System::Collections::Generic;

	public ref class PreferencesForm : public System::Windows::Forms::Form
	{
	public:
		PreferencesForm(SortedDictionary<String^, bool>^ genres, MusicPlayer^ _player);

	private:
		System::Windows::Forms::Button^  okButton;
		System::Windows::Forms::Button^  cancelButton;
		System::Windows::Forms::Label^  workLabel;
		System::Windows::Forms::Label^  gamingLabel;
		System::Windows::Forms::Label^  otherLabel;
		System::Windows::Forms::CheckedListBox^  workBox;
		System::Windows::Forms::CheckedListBox^  gamingBox;
		System::Windows::Forms::CheckedListBox^  otherBox;
		System::ComponentModel::Container ^components;

		Generic::List<String^>^ workPreferences;
		Generic::List<String^>^ gamingPreferences;
		Generic::List<String^>^ otherPreferences;

		MusicPlayer^ player;

		System::Void cancelButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void okButton_Click(System::Object^  sender, System::EventArgs^  e);
		System::Void workBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e);

#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			this->okButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->workLabel = (gcnew System::Windows::Forms::Label());
			this->gamingLabel = (gcnew System::Windows::Forms::Label());
			this->otherLabel = (gcnew System::Windows::Forms::Label());
			this->workBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->gamingBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->otherBox = (gcnew System::Windows::Forms::CheckedListBox());
			this->SuspendLayout();
			// 
			// okButton
			// 
			this->okButton->Location = System::Drawing::Point(71, 303);
			this->okButton->Name = L"okButton";
			this->okButton->Size = System::Drawing::Size(75, 23);
			this->okButton->TabIndex = 0;
			this->okButton->Text = L"OK";
			this->okButton->UseVisualStyleBackColor = true;
			this->okButton->Click += gcnew System::EventHandler(this, &PreferencesForm::okButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->Location = System::Drawing::Point(199, 303);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(75, 23);
			this->cancelButton->TabIndex = 1;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &PreferencesForm::cancelButton_Click);
			// 
			// workLabel
			// 
			this->workLabel->AutoSize = true;
			this->workLabel->Location = System::Drawing::Point(3, 9);
			this->workLabel->Name = L"workLabel";
			this->workLabel->Size = System::Drawing::Size(33, 13);
			this->workLabel->TabIndex = 2;
			this->workLabel->Text = L"Work";
			// 
			// gamingLabel
			// 
			this->gamingLabel->AutoSize = true;
			this->gamingLabel->Location = System::Drawing::Point(3, 102);
			this->gamingLabel->Name = L"gamingLabel";
			this->gamingLabel->Size = System::Drawing::Size(43, 13);
			this->gamingLabel->TabIndex = 4;
			this->gamingLabel->Text = L"Gaming";
			// 
			// otherLabel
			// 
			this->otherLabel->AutoSize = true;
			this->otherLabel->Location = System::Drawing::Point(3, 201);
			this->otherLabel->Name = L"otherLabel";
			this->otherLabel->Size = System::Drawing::Size(33, 13);
			this->otherLabel->TabIndex = 6;
			this->otherLabel->Text = L"Other";
			// 
			// workBox
			// 
			this->workBox->FormattingEnabled = true;
			this->workBox->Location = System::Drawing::Point(6, 25);
			this->workBox->Name = L"workBox";
			this->workBox->Size = System::Drawing::Size(330, 64);
			this->workBox->TabIndex = 7;
			// 
			// gamingBox
			// 
			this->gamingBox->FormattingEnabled = true;
			this->gamingBox->Location = System::Drawing::Point(6, 118);
			this->gamingBox->Name = L"gamingBox";
			this->gamingBox->Size = System::Drawing::Size(330, 64);
			this->gamingBox->TabIndex = 8;
			// 
			// otherBox
			// 
			this->otherBox->FormattingEnabled = true;
			this->otherBox->Location = System::Drawing::Point(6, 217);
			this->otherBox->Name = L"otherBox";
			this->otherBox->Size = System::Drawing::Size(330, 64);
			this->otherBox->TabIndex = 9;
			// 
			// PreferencesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 340);
			this->Controls->Add(this->otherBox);
			this->Controls->Add(this->gamingBox);
			this->Controls->Add(this->workBox);
			this->Controls->Add(this->otherLabel);
			this->Controls->Add(this->gamingLabel);
			this->Controls->Add(this->workLabel);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->okButton);
			this->Name = L"PreferencesForm";
			this->Text = L"Preferences";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	};
}
