#pragma once
#include"SFML/Graphics.hpp"
#include<Vector>
using namespace std;
class Grid
{
public:
	Grid(float window_width, float window_height, float square_dimention, sf::Mouse& mouse , sf::RenderWindow& window);
	void DrawGrid();
	void setStart();
	void setTarget();
	sf::Vector2i getmousepostition();

	
private:
	float window_width, window_height, square_dimention, xtiles, ytiles;
	vector<sf::RectangleShape> TileMap;
	sf::Mouse& mouse;
	sf::RenderWindow& window;
	sf::Vector2i Startpos, Targetpos;
	sf::Vector2i prevStartpos, prevTargetpos;

	sf::Vector2i Mousepos;
	
	sf::Color DefaultColor = sf::Color::Blue;
	sf::Color StartColor = sf::Color::Yellow;
	sf::Color targetColor = sf::Color::Red;
	sf::Color obstacleColor = sf::Color::Black;

};

