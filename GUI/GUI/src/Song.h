#pragma once

public ref class Song {
public:
	Song();
	Song(System::String^ n);

	property System::String^ SongName {
		System::String^ get() {
			return name;
		}
	}

private:
	System::String^ name;
};