#include "Application.h"

Application::Application(float window_width, float window_height, float square_dimention)
{
	sf::Mouse m;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Graph PathFinding Visualizer", sf::Style::Close);
	window.setKeyRepeatEnabled(false);
	Grid G1(window_width, window_height, square_dimention,m, window);
	Graph graph(G1);
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
		G1.DrawGrid();

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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
		{
			G1.resetGrid();
		}
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
		{
			G1.clearAfterAlgorithm();
			BFS bfs(graph);
			bfs.solveAlgorithm(G1, G1.getstart(), G1.getTarget(), G1.getObstacles());
			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
		{
			G1.clearAfterAlgorithm();
			DFS dfs(graph);
			dfs.solveAlgorithm(G1, G1.getstart(), G1.getTarget(), G1.getObstacles());
		}
		window.display();
		//graph.resetGraph();
	}
	//G1.DrawGrid();
	//BFS A1(graph);
	//A1.solveAlgorithm(G1, G1.getstart(), G1.getTarget(), G1.getObstacles());
	
}
