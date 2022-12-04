#pragma once
#include"SFML/Graphics.hpp"
#include<Vector>
#include<iostream>
//#include "Graph.h"
using namespace std;
class Grid
{
public:
	Grid(float window_width, float window_height, float square_dimention, sf::Mouse& mouse , sf::RenderWindow& window);
	void DrawGrid();
	void setStart();
	void setTarget();
	void setObstacle();
	int getXtiles();
	int getYtiles();
	int getNumtiles();
	float getsquareDim();
	//void setGraph(Graph& graph);
	vector<sf::RectangleShape> getTileMap();


	sf::Vector2i getstart();
	sf::Vector2i getTarget();
	sf::RenderWindow& getwindow();
	
	sf::Vector2i getmousepostition();
	sf::Color getTilecolor(sf::Vector2i );
	void setTilecolor(sf::Vector2i , sf::Color);
	//void getnode(Graph::node)

	
private:
	float window_width, window_height, square_dimention, xtiles, ytiles;
	vector<sf::RectangleShape> TileMap;
	vector<sf::Vector2i> Obstaclespos; vector<sf::Vector2i>::iterator it;
	int obstacleindex=0;
	sf::Mouse& mouse;
	sf::RenderWindow& window;
	sf::Vector2i Startpos, Targetpos;
	sf::Vector2i prevStartpos, prevTargetpos;
	sf::Vector2i Mousepos;
	
	sf::Color DefaultColor = sf::Color::White;
	sf::Color StartColor = sf::Color::Yellow;
	sf::Color targetColor = sf::Color::Red;
	sf::Color obstacleColor = sf::Color::Black;
	

};

