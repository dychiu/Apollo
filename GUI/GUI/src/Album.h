#pragma once

public ref class Album {
public:
	Album();
	Album(System::String^ n);

	property System::String^ ArtistName {
		System::String^ get() {
			return name;
		}
	}

private:
	System::String^ name;
};