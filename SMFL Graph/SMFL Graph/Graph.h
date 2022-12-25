#pragma once
#include"Grid.h"
class Graph
{

private:
	
	
public:
	class node
	{
	public:

		int x, y;
		vector<node*> neighbours;
		bool obstacle = false;
		bool visited = false;
	};
	Grid& G1;
	vector<node> nodes;
	vector<node*> getneighbours(node n);
	Graph(Grid& grid);
	node& getnode(int, int);
	Grid& getGrid();
	void setObstacles();
	void isObstacle();
	void resetGraph();
	//3ayzeen reset el graph
};

