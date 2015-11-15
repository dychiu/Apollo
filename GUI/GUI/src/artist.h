#pragma once

public ref class Artist {
public:
	Artist();
	Artist(System::String^ n);

	property System::String^ ArtistName {
		System::String^ get() {
			return name;
		}
	}

private:
	System::String^ name;
};