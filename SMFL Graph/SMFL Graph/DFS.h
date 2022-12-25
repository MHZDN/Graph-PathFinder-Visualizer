#pragma once
#include "Graph.h"
#include<thread>
#include <stack>
class DFS
{
public:
	DFS(Graph& graph);
	void solveAlgorithm(Grid& grid, const sf::Vector2i& startpos, const sf::Vector2i& targetpos, const vector<sf::Vector2i>& obstacles);
private:
	Graph& graph;
	sf::Vector2i startpos, targetpos;
	vector<sf::Vector2i> obstacles;
	stack<Graph::node*> stack;
	bool targetReached = false;
};

