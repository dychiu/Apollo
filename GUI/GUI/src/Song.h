#pragma once

public ref class Song {
public:
	Song();
	Song(System::String^ n);

	property System::String^ ArtistName {
		System::String^ get() {
			return name;
		}
	}

private:
	System::String^ name;
};