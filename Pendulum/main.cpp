#include <SFML/Graphics.hpp>
#include <Windows.h>
#include <iostream>
#include <ctime>
#include "Pend.cpp"

using namespace std;

void main() {
	pendul::Pendulum May;
	int FPS = 300;
	time_t T = clock();
	cout << "Amplitude:" << endl;
	cin >> May.Amplitude;
	cout << "Len:" << endl;
	cin >> May.len;
	cout << clock();
	pair <int, int> cord = May.move((float(clock()-T))/CLOCKS_PER_SEC);
	cord.first = 500 - cord.first;
	cord.second = cord.second;

	sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
	sf::CircleShape shape(10 * May.radius);
	sf::Vertex line[] = { sf::Vertex(sf::Vector2f(500, 0)), sf::Vertex(sf::Vector2f(cord.first+May.radius, cord.second+May.radius)) };
	shape.setFillColor(sf::Color::White);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		line[1] = sf::Vertex(sf::Vector2f(cord.first+May.radius, cord.second+May.radius));
		shape.setPosition(cord.first, cord.second);
		Sleep(1000 / FPS);
		window.clear();
		window.draw(shape);
		window.draw(line, 2, sf::Lines);
		window.display();


		cord = May.move((float(clock() - T)) / CLOCKS_PER_SEC);
		cord.first = 500 - cord.first;
		cord.second = cord.second;
	}

}