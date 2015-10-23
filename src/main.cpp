#include <SFML/Audio.hpp>
#include <iostream>

int main() {
	sf::Music music;

	if (!music.openFromFile("C:\\Users\\jonat\\University\\3rd_Year\\320\\Project\\walnut\\test\\scholarships.flac")) {
		std::cout << "Unable to open music file";
	}
	else {
		std::cout << "Playing!" << std::endl;
		music.setLoop(true);
		music.setVolume(50);
		music.play();
		getchar();
	}
}