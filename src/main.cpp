#include <SFML/Audio.hpp>
#include <iostream>
int main() {
	sf::Music music;

	if (!music.openFromFile("data/sounds/music.wav")) {
		std::cout << "Error...";
	}
	else {
		music.setLoop(true);
		music.setVolume(50);
		music.play();
	}

}