#include <SFML/Audio.hpp>
#include <iostream>
#include <taglib/tag.h>
#include <taglib/fileref.h>

int main()
{
	//Music object needs to be created here or it
	//will go out of scope and be destroyed
	sf::Music test;
	std::string filepath = "../SFML_Test/test/scholarships.flac";
	std::string input;
	bool validInput = false;
	std::cout << "1. Test generic music playback" << std::endl << "2. Test mp3 playback" << std::endl << "3. Test tag reading" << std::endl;

	while (!validInput) {
		std::cout << "Enter a number: ";
		std::cin >> input;
		std::cout << std::endl;

		if (input == "1") {
			if (!test.openFromFile(filepath)) {
				std::cout << "Unable to open music file";
			}
			else {
				std::cout << "Playing!" << std::endl;
				test.setLoop(true);
				test.setVolume(50);
				test.play();
			}
			validInput = true;
		}
		else if (input == "2") {
			std::cout << "Option 2" << std::endl;
			validInput = true;
		}
		else if (input == "3") {
			std::cout << "Option 3" << std::endl;
			TagLib::FileRef f(filepath.c_str());
			TagLib::String artist = f.tag()->artist();
			std::cout << "Artist is: " << artist << std::endl;
			system("pause");
			validInput = true;

		}
	}
	system("pause");
	return 0;
}