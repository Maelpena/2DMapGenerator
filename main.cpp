#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include "Display.h"
#include "MapGenerator.h"

int main()
{
	MapGenerator* map = new MapGenerator(301);
	map->generate();
	Display* display = new Display(map);
	display->update();

	delete display;

	return 0;
}