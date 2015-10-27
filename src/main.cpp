//#include <SFML/Graphics.hpp>
//test
#include <SFML/Audio.hpp>
#include <iostream>

int main()
{
	/*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);*/
	sf::Music test;

	if (!test.openFromFile("C:\\Users\\jonat\\University\\3rd_Year\\320\\Project\\walnut\\test\\scholarships.flac")) {
		std::cout << "Unable to open music file";
	}
	else {
		std::cout << "Playing!" << std::endl;
		test.setLoop(true);
		test.setVolume(50);
		test.play();
	}
	/*while (window.isOpen())
	{
	sf::Event event;
	while (window.pollEvent(event))
	{
	if (event.type == sf::Event::Closed)
	window.close();
	}

	window.clear();
	window.draw(shape);
	window.display();
	}*/
	system("pause");
	return 0;
}