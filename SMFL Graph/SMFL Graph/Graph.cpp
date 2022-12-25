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
	//setObstacles();
}

vector<Graph::node*> Graph::getneighbours(node n)
{
	return n.neighbours;
}

Graph::node& Graph::getnode(int x, int y)
{
	return nodes[x * G1.getXtiles() + y];
}


Grid& Graph::getGrid()
{
	return G1;
}

void Graph::setObstacles()
{
	sf::Color o= sf::Color::Black;
	for (int i = 0; i < G1.getNumtiles(); i++)
	{
		if (G1.getTileMap()[i].getFillColor() == o)
		{
			nodes[i].obstacle = true;
		}
	}
}

void Graph::isObstacle()
{
	vector<sf::RectangleShape> Tilemap = G1.getTileMap();
	if (nodes[G1.getIndex()].obstacle)
	{
		cout << "True";
	}
	else { cout << "False"; }


}

void Graph::resetGraph()
{
	for (auto& node : nodes)
	{
		node.visited = false;
		node.obstacle = false;
		
	}
}



