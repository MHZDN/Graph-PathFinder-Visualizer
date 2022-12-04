#include "Graph.h"

Graph::Graph(Grid& grid)
	:G1(grid)
{
	
	int Ytiles = grid.getYtiles(), Xtiles = grid.getXtiles();
	nodes.resize(grid.getNumtiles());
	//cout << nodes.size();
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i].x = static_cast<int>(grid.getTileMap()[i].getPosition().x / grid.getsquareDim());
		nodes[i].y = static_cast<int>(grid.getTileMap()[i].getPosition().y / grid.getsquareDim());

		if (nodes[i].x > 0 && nodes[i].x < Xtiles - 1 && nodes[i].y > 0 && nodes[i].y < Ytiles - 1) //inside frame
		{
			nodes[i].neighbours.emplace_back(&nodes[i + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles + 1]);
		}
		else if (nodes[i].x > 0 && nodes[i].x < Xtiles - 1 && nodes[i].y == 0) //top frame
		{
			nodes[i].neighbours.emplace_back(&nodes[i + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles + 1]);
		}
		else if (nodes[i].x > 0 && nodes[i].x < Xtiles - 1 && nodes[i].y == Ytiles - 1) //bottom frame
		{
			nodes[i].neighbours.emplace_back(&nodes[i - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles - 1]);
		}
		else if (nodes[i].x == 0 && nodes[i].y > 0 && nodes[i].y < Ytiles - 1)  // left frame
		{
			nodes[i].neighbours.emplace_back(&nodes[i + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles + 1]);
		}
		else if (nodes[i].x == Xtiles - 1 && nodes[i].y > 0 && nodes[i].y < Ytiles - 1) //right frame
		{
			nodes[i].neighbours.emplace_back(&nodes[i + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles - 1]);
		}

		else if (nodes[i].x == 0 && nodes[i].y == 0) //left top corener
		{
			nodes[i].neighbours.emplace_back(&nodes[i + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles + 1]);
		}

		else if (nodes[i].x == Xtiles - 1 && nodes[i].y == 0) // right top corner 
		{
			nodes[i].neighbours.emplace_back(&nodes[i + 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles + 1]);
		}
		else if (nodes[i].x == 0 && nodes[i].y == Ytiles - 1) // left bottom corner
		{
			nodes[i].neighbours.emplace_back(&nodes[i - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i + Ytiles - 1]);
		}
		else if (nodes[i].x == Xtiles - 1 && nodes[i].y == Ytiles - 1) //right bottom corner
		{
			nodes[i].neighbours.emplace_back(&nodes[i - 1]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles]);
			nodes[i].neighbours.emplace_back(&nodes[i - Ytiles - 1]);
		}
	}
}

vector<Graph::node*> Graph::getneighbours(node n)
{
	return n.neighbours;
}

Graph::node Graph::getnode(int x, int y)
{
	return nodes[x * G1.getXtiles() + y];
}

void Graph::showNodeandNeghbours()
{
	sf::Event event;
	while (G1.getwindow().isOpen())
	{
		while (G1.getwindow().pollEvent(event))
		{
			switch (event.type)
			{
			case(sf::Event::Closed):
				G1.getwindow().close();
				break;

			}


		}
		for (int i = 0; i < G1.getXtiles() * G1.getYtiles(); i++)
		{
			G1.getwindow().draw(G1.getTileMap()[i]);
		}
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.key.code == sf::Mouse::Left)
			{
				G1.setStart();
			}
			else if (event.key.code == sf::Mouse::Right)
			{
				G1.setTarget();
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::O))
		{
			G1.setObstacle();
		}

		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
		{
			int xmous = G1.getmousepostition().x/G1.getsquareDim(); int ymous = G1.getmousepostition().y/G1.getsquareDim();
			node n = nodes[xmous * G1.getXtiles() + ymous];
			cout << "my pos: " << n.x << "  " << n.y << "\n";
			/*for (vector<node*>::iterator it = n.neighbours.begin(); it < n.neighbours.end(); it++)
			{
				cout<< **it.;
			}*/
			cout << "neighbours:\n";
			for (int i = 0; i < n.neighbours.size(); i++)
			{
				cout << (n.neighbours[i]->x) << " " << (n.neighbours[i]->y)<<"\n";
			}

		}
		G1.getwindow().display();
	}
}



