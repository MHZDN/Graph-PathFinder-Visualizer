#include "Application.h"

Application::Application(float window_width, float window_height, float square_dimention)
{
	sf::Mouse m;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Graph PathFining Visualizer", sf::Style::Close);
	window.setKeyRepeatEnabled(false);
	Grid G1(window_width, window_height, square_dimention,m, window);
	G1.DrawGrid();
	
}
