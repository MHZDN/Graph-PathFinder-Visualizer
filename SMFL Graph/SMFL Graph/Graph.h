#pragma once
#include"Grid.h"
class Graph
{

private:
	class node
	{
	public:

		int x, y;
		vector<node*> neighbours;

	};
	Grid& G1;
	vector<node> nodes;
	
public:
	Graph(Grid& grid);
	vector<node*> getneighbours(node n);
	node getnode(int, int);
	void showNodeandNeghbours();

};

