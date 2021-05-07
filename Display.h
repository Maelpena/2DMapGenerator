#pragma once
#include <SFML/Graphics.hpp>
#include "MapGenerator.h"

class Display {
public:
	Display(MapGenerator*);
	~Display();

	void update();

private:
	int m_screenSize;
	MapGenerator* m_map;
	sf::RenderWindow m_window;
	sf::View m_view;
	float m_moveSpeed;
	int m_mapSize;
};