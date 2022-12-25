#include "BFS.h"

 BFS::BFS(Graph& graph)
	:graph(graph)
{
}

 void BFS::solveAlgorithm(Grid& grid,const sf::Vector2i& startpos, const sf::Vector2i& targetpos, const vector<sf::Vector2i>& obstacles)
 {
	 this->startpos = startpos;
	 this->targetpos = targetpos;

	 for (const auto& obs : obstacles)
	 {
		 graph.getnode(obs.x, obs.y).obstacle = true;
	 }
	 Graph::node* startnode = &(graph.getnode(startpos.x, startpos.y));
	 queue.emplace_back(startnode);
	 startnode->visited = true;
	 while (!(queue.empty()) && !targetReached)
	 {
		 Graph::node* curr = queue.front();
		 
		 if (curr->x == targetpos.x && curr->y == targetpos.y)   { targetReached = true; }
		 queue.pop_front();
		 if (!((curr->x == startpos.x && curr->y == startpos.y)) && !(curr->x == targetpos.x && curr->y == targetpos.y) ) { graph.G1.setcurrent(curr->x, curr->y); }

		 grid.DrawGrid();
		 grid.getwindow().display();
		 this_thread::sleep_for(chrono::milliseconds(10));
		 for (const auto& n : curr->neighbours)
		 {
			 if (!(n->visited))
			 {
				 if (!(n->obstacle)) 
				 {
					 queue.emplace_back(n);
					 if (!(n->x == targetpos.x && n->y == targetpos.y))
					 {
						 graph.G1.setnext(n->x, n->y);
					 }
					 n->visited = true;

				 }
			 }


		 }


	 }
	 graph.resetGraph();
	 /*grid.resetGrid();*/

 }
