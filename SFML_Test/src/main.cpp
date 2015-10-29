#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	sf::Music test;

	//Need to figure out relative filepaths, as they currently don't work.
	if (!test.openFromFile("C:\\Users\\jonat\\University\\3rd_Year\\320\\Project\\walnut\\SFML_Test\\test\\test_ogg.ogg")) {
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