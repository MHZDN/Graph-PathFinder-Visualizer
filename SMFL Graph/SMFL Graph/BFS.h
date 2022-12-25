#include "Graph.h"
#include <deque>
#include<thread>


#pragma once
class BFS
{
public:
	 BFS(Graph & graph);
	 void solveAlgorithm(Grid &grid,const sf::Vector2i& startpos, const sf::Vector2i& targetpos, const vector<sf::Vector2i>& obstacles );
private:
	Graph &graph;
	sf::Vector2i startpos, targetpos;
	vector<sf::Vector2i> obstacles;
	deque<Graph::node*> queue;
	bool targetReached = false;
	
};

