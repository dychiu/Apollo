#include "PreferencesForm.h"

using namespace GUI;

PreferencesForm::PreferencesForm(MusicPlayer^ _player) {
	InitializeComponent();
	player = _player;
	genres = player->getMusicLibrary()->getGenreList();

	workPreferences = player->getMusicLibrary()->getWorkPreferences();
	gamingPreferences = player->getMusicLibrary()->getGamingPreferences();
	otherPreferences = player->getMusicLibrary()->getOtherPreferences();

	for each (String^ s in genres) {
		if (!String::IsNullOrWhiteSpace(s))
			workBox->Items->Add(s);
	}

	for (int i = 0; i < workBox->Items->Count; i++) {
		if (workPreferences->IndexOf(workBox->Items[i]->ToString()) != -1)
			workBox->SetItemChecked(i, true);
	}

	for each (String^ s in genres) {
		if (!String::IsNullOrWhiteSpace(s))
			gamingBox->Items->Add(s);
	}

	for (int i = 0; i < gamingBox->Items->Count; i++) {
		if (gamingPreferences->IndexOf(gamingBox->Items[i]->ToString()) != -1)
			gamingBox->SetItemChecked(i, true);
	}

	for each (String^ s in genres) {
		if (!String::IsNullOrWhiteSpace(s))
			otherBox->Items->Add(s);
	}

	for (int i = 0; i < otherBox->Items->Count; i++) {
		if (otherPreferences->IndexOf(otherBox->Items[i]->ToString()) != -1)
			otherBox->SetItemChecked(i, true);
	}

	//If there are no checked boxes, set them all as true
	if (otherBox->CheckedItems->Count == 0) {
		for (int i = 0; i < otherBox->Items->Count; i++) {
			otherBox->SetItemChecked(i, true);
		}
	}
}


System::Void PreferencesForm::cancelButton_Click(System::Object^  sender, System::EventArgs^  e) {
	Close();
}

System::Void PreferencesForm::okButton_Click(System::Object^  sender, System::EventArgs^  e) {
	// need to save preferences upon close
	workPreferences = gcnew List<String^>();
	for each (String^ item in workBox->CheckedItems) {
		workPreferences->Add(item);
	}
	gamingPreferences = gcnew List<String^>();
	for each (String^ item in gamingBox->CheckedItems) {
		gamingPreferences->Add(item);
	}
	otherPreferences = gcnew List<String^>();
	for each (String^ item in otherBox->CheckedItems) {
		otherPreferences->Add(item);
	}

	if (otherPreferences->Count == 0) {
		System::Windows::Forms::MessageBox^ error;
		error->Show("Other must have at least one genre selected!", "Error!");
		return;
	}

	player->getMusicLibrary()->setWorkPreferences(workPreferences);
	player->getMusicLibrary()->setGamingPreferences(gamingPreferences);
	player->getMusicLibrary()->setOtherPreferences(otherPreferences);

	player->getMusicLibrary()->save();
	Close();
}

System::Void PreferencesForm::workBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
	// Need to check which items are checked and to save them in that state for form reloading	

}