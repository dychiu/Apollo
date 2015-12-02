#include "PreferencesForm.h"

using namespace GUI;

PreferencesForm::PreferencesForm(MusicPlayer^ _player) {
	InitializeComponent();
	player = _player;
	genres = player->getMusicLibrary()->getGenreList();

	for each (String^ s in genres) {
		if (!String::IsNullOrWhiteSpace(s))
			workBox->Items->Add(s);
	}

	for each (String^ s in genres) {
		if (!String::IsNullOrWhiteSpace(s))
			gamingBox->Items->Add(s);
	}

	for each (String^ s in genres) {
		if (!String::IsNullOrWhiteSpace(s))
			otherBox->Items->Add(s);
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
	player->getMusicLibrary()->setWorkPreferences(workPreferences);
	player->getMusicLibrary()->setGamingPreferences(gamingPreferences);
	player->getMusicLibrary()->setOtherPreferences(otherPreferences);

	player->getMusicLibrary()->save();
	Close();
}

System::Void PreferencesForm::workBox_ItemCheck(System::Object^ sender, System::Windows::Forms::ItemCheckEventArgs^ e) {
	// Need to check which items are checked and to save them in that state for form reloading	

}