#include <SFML/Audio.hpp>
#include <iostream>

int main() {
	std::string filepath = "C:\\Users\\jonat\\University\\3rd_Year\\320\\Project\\walnut\\test\\scholarships.flac";
	std::string input;
	std::cout << "1. Test music playback" << std::endl << "2. Test tag reading" << std::endl << "Enter a number: ";
	std::cin >> input;
	std::cout << std::endl;

	if (input == "1") {
		/*sf::Music music;

		if (!music.openFromFile(filepath)) {
		std::cout << "Unable to open music file";
		}
		else {
		std::cout << "Playing!" << std::endl;
		music.setLoop(true);
		music.setVolume(50);
		music.play();
		getchar();
		}*/
		std::cout << "testing1" << std::endl;
	}
	else if (input == "2") {
		std::cout << "testing2" << std::endl;
	}
}