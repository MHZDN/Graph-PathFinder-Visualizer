#include "Grid.h"


Grid::Grid(float window_width, float window_height, float square_dimention, sf::Mouse& mouse , sf::RenderWindow& window)
	:window_width(window_width), window_height(window_height), square_dimention(square_dimention), mouse(mouse), window(window)
{
	xtiles = static_cast<int>(window_width / square_dimention);
	ytiles = static_cast<int>( window_height / square_dimention);
	TileMap.resize(xtiles * ytiles);
	
	//intialization for start and taregt
	//it = Obstaclespos.begin();
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
			TileMap[i * xtiles + j].setFillColor(DefaultColor);
			TileMap[i * xtiles + j].setOutlineThickness(1);
			TileMap[i * xtiles + j].setOutlineColor(sf::Color::Black);

		}
	}
	TileMap[Startpos.x * xtiles + Startpos.y].setFillColor(StartColor);
	TileMap[Targetpos.x * xtiles + Targetpos.y].setFillColor(targetColor);

}

void Grid::DrawGrid()
{

	for (const auto& tiles : TileMap)
	{
		window.draw(tiles);
	}
	//window.display();
	
	/*sf::Event event;
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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O))
		{
			setObstacle();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::I))
		{
			isObstacle();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			resetGrid();
		}
		
		window.display();


	}*/
}



sf::Vector2i Grid::getmousepostition()
{
	Mousepos = mouse.getPosition(window);
	cout << Mousepos.x << "  " << Mousepos.y << "\n";
	return Mousepos;
}

bool Grid::falsemousepos(int x, int y)
{
	
	return (x < 0 || y < 0 || x>=xtiles || y>=ytiles);
}

sf::Color Grid::getTilecolor(sf::Vector2i pos)
{
	return 	TileMap[pos.x * xtiles + pos.y].getFillColor();

}

void Grid::setTilecolor(sf::Vector2i pos, sf::Color color)
{
	TileMap[pos.x * xtiles + pos.y].setFillColor(color);
}

void Grid::resetGrid()
{
	Obstaclespos.clear();
	Startpos = { 0,0 };                            //start index
	Targetpos.x = xtiles - 1;     Targetpos.y = ytiles - 1; //target index

	prevStartpos = { Startpos.x,Startpos.y };
	prevTargetpos = { Targetpos.x,Targetpos.y };


	for (int i = 0; i < xtiles; i++)
	{
		for (int j = 0; j < ytiles; j++)
		{
			TileMap[i * xtiles + j].setFillColor(DefaultColor);
		}
	}
	TileMap[Startpos.x * xtiles + Startpos.y].setFillColor(StartColor);
	TileMap[Targetpos.x * xtiles + Targetpos.y].setFillColor(targetColor);
}

void Grid::clearAfterAlgorithm()
{
	for (auto& tile : TileMap)
	{
		if (tile.getFillColor() == StartColor || tile.getFillColor() == targetColor || tile.getFillColor() == obstacleColor)
		{
			continue;
		}
		else
		{
			tile.setFillColor(DefaultColor);
		}
	}
}

void Grid::setStart()
{
		getmousepostition();
		Startpos.x = static_cast<int>(Mousepos.x / square_dimention);
		Startpos.y = static_cast<int>(Mousepos.y / square_dimention);
		if (falsemousepos(Startpos.x, Startpos.y)) { return; }
		setTilecolor(prevStartpos, DefaultColor); //reset old start

		setTilecolor(Startpos, StartColor); // set new start

		prevStartpos = { Startpos.x ,Startpos.y };  //setting new previous
}

void Grid::setTarget()
{
	getmousepostition();
		Targetpos.x = static_cast<int>( Mousepos.x / square_dimention);
		Targetpos.y = static_cast<int>( Mousepos.y / square_dimention);
		if (falsemousepos(Targetpos.x, Targetpos.y)) { return; }
		
		setTilecolor(prevTargetpos, DefaultColor);  		 //reset old target

		setTilecolor(Targetpos, targetColor);				 // set new target


		prevTargetpos = { Targetpos.x ,Targetpos.y };     //setting new previous
}

void Grid::setObstacle()
{
	getmousepostition();
	
	sf::Vector2i obstaclepos = { static_cast<int>(Mousepos.x / square_dimention) ,static_cast<int>(Mousepos.y / square_dimention )};
	if (falsemousepos(obstaclepos.x, obstaclepos.y)) { return; }
	if (getTilecolor(obstaclepos) == obstacleColor || getTilecolor(obstaclepos) == StartColor || getTilecolor(obstaclepos) == targetColor)
	{
		return;
	}
	
	Obstaclespos.emplace_back(obstaclepos);
	setTilecolor(obstaclepos, obstacleColor);
	
}

void Grid::setcurrent(int x, int y)
{
	sf::Vector2i pos={x,y};
	setTilecolor(pos, currentColor);
}

void Grid::setnext(int x, int y)
{
	sf::Vector2i pos = { x,y };
	setTilecolor(pos, nextColor);
}



int Grid::getXtiles()
{
	return static_cast<int>(xtiles);
}

int Grid::getYtiles()
{
	return static_cast<int>(ytiles);
}

int Grid::getNumtiles()
{
	return static_cast<int>(xtiles*ytiles);
}

float Grid::getsquareDim()
{
	return square_dimention;
}

int Grid::getIndex()
{
	getmousepostition();
	int x= static_cast<int>(Mousepos.x / square_dimention) , y= static_cast<int>(Mousepos.y / square_dimention);
	return (x*xtiles+ytiles);
}

void Grid::isObstacle()
{
	if (TileMap[getIndex()].getFillColor() == obstacleColor)
	{
		cout << "True";
	}
	else
		cout << "Flase";
}





vector<sf::RectangleShape> Grid::getTileMap() 
{
	return TileMap;
}

vector<sf::Vector2i> Grid::getObstacles()
{
	return Obstaclespos;
}

sf::Vector2i Grid::getstart()
{
	return Startpos;
}

sf::Vector2i Grid::getTarget()
{
	return Targetpos;
}

sf::RenderWindow& Grid::getwindow()
{
	return window;
}
