#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	sf::Music test;

	if (!test.openFromFile("C:\\Users\\jonat\\University\\3rd_Year\\320\\Project\\SFML_Test\\Debug\\test_ogg.ogg")) {
		std::cout << "Unable to open music file";
	}
	else {
		std::cout << "Playing!" << std::endl;
		test.setLoop(true);
		test.setVolume(50);
		test.play();
	}
	system("pause");
	return 0;
}