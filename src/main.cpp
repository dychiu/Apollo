#include <SFML/Audio.hpp>
#include <iostream>
int main() {
	sf::Music music;

	if (!music.openFromFile("../test/scholarships.flac")) {
		std::cout << "Unable to open music file";
	}
	else {
		music.setLoop(true);
		music.setVolume(50);
		music.play();
	}
}
