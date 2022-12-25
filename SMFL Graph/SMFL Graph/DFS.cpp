#include "DFS.h"

DFS::DFS(Graph& graph)
	:graph(graph)
{
}

void DFS::solveAlgorithm(Grid& grid, const sf::Vector2i& startpos, const sf::Vector2i& targetpos, const vector<sf::Vector2i>& obstacles)
{
	this->startpos = startpos;
	this->targetpos = targetpos;

	for (const auto& obs : obstacles)
	{
		graph.getnode(obs.x, obs.y).obstacle = true;
	}

	Graph::node* StartNode = &(graph.getnode(startpos.x, startpos.y));
	stack.push(StartNode);
	
	StartNode->visited = true;
	

	while (!(stack.empty()) && !targetReached)
	{
		Graph::node* curr = stack.top();
		stack.pop();

		if (curr->x == targetpos.x && curr->y == targetpos.y) {targetReached = true;}

		if (!(curr->x == targetpos.x && curr->y == targetpos.y) && !(curr->x == startpos.x && curr->y == startpos.y))
		{
		graph.G1.setcurrent(curr->x, curr->y);
		}
		grid.DrawGrid();
		grid.getwindow().display();
		this_thread::sleep_for(chrono::milliseconds(40));
		for (const auto& neighbour : curr->neighbours)
		{

			if (!neighbour->visited)
			{
				if (!neighbour->obstacle)
				{
					stack.push(neighbour);
					if (!(neighbour->x == targetpos.x && neighbour->y == targetpos.y))
					{
						graph.G1.setnext(neighbour->x, neighbour->y);
					}
					neighbour->visited = true;
				}
			}
		}
	}
	graph.resetGraph();
}
