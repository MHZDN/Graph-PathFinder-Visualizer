#include "Grid.h"
#include<iostream>

Grid::Grid(float window_width, float window_height, float square_dimention, sf::Mouse& mouse , sf::RenderWindow& window)
	:window_width(window_width), window_height(window_height), square_dimention(square_dimention), mouse(mouse), window(window)
{
	xtiles = static_cast<int>(window_width / square_dimention);
	ytiles = static_cast<int>( window_height / square_dimention);
	TileMap.resize(xtiles * ytiles);
	
	//intialization for start and taregt
	Startpos = {0,0};                            //start index
	Targetpos.x = xtiles - 1;     Targetpos.y = ytiles - 1; //target index

	prevStartpos = { Startpos.x,Startpos.y };
	prevTargetpos = { Targetpos.x,Targetpos.y };


	for (int i = 0; i < xtiles; i++)
	{
		for (int j = 0; j < ytiles; j++)
		{
			TileMap[i * xtiles + j].setSize(sf::Vector2f(square_dimention, square_dimention));
			TileMap[i * xtiles + j].setPosition(i*square_dimention,j*square_dimention);
			TileMap[i * xtiles + j].setFillColor(sf::Color::Blue);
			TileMap[i * xtiles + j].setOutlineThickness(1);
			TileMap[i * xtiles + j].setOutlineColor(sf::Color::Black);

		}
	}
	TileMap[Startpos.x * xtiles + Startpos.y].setFillColor(StartColor);
	TileMap[Targetpos.x * xtiles + Targetpos.y].setFillColor(targetColor);

}

void Grid::DrawGrid()
{
	
	sf::Event event;
	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::Closed):
				window.close();
				break;
			
			}
			

		}
		for (int i = 0; i < xtiles * ytiles; i++)
		{
			window.draw(TileMap[i]);
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				setStart();
			}
			else if(event.key.code == sf::Mouse::Right)
			{
				setTarget();
			}
		}
		
		window.display();


	}
}



sf::Vector2i Grid::getmousepostition()
{
	Mousepos = mouse.getPosition(window);
	cout << Mousepos.x << "  " << Mousepos.y << "\n";
	return Mousepos;
}

void Grid::setStart()
{
		getmousepostition();
		Startpos.x = static_cast<int>(Mousepos.x / square_dimention);
		Startpos.y = static_cast<int>(Mousepos.y / square_dimention);
		
		TileMap[prevStartpos.x * xtiles + prevStartpos.y].setFillColor(DefaultColor); //reset old start

		TileMap[Startpos.x * xtiles + Startpos.y].setFillColor(StartColor); // set new start

		prevStartpos = { Startpos.x ,Startpos.y };  //setting new previous


	
}

void Grid::setTarget()
{
	getmousepostition();
		Targetpos.x = static_cast<int>( Mousepos.x / square_dimention);
		Targetpos.y = static_cast<int>( Mousepos.y / square_dimention);
		
		TileMap[prevTargetpos.x * xtiles + prevTargetpos.y].setFillColor(DefaultColor); //reset old target


		TileMap[Targetpos.x * xtiles + Targetpos.y].setFillColor(targetColor); // set new target

		prevTargetpos = { Targetpos.x ,Targetpos.y };     //setting new previous
}
