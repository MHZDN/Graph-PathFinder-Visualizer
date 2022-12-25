#include <SFML/Graphics.hpp>
#include <iostream>
#include<Vector>
#include"Application.h"

using namespace std;
int main()
{
	
	//sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Close | sf::Style::Resize); //Style hoa no3 el screen bey3emlha resize wala sabta wala full screen
	//sf::RectangleShape player(sf::Vector2f(100.0f, 100.0f)); //vector 2f =>float //vector 2i =>integr //vector  2u => unsigned integer 
	//
	//player.setFillColor(sf::Color::White);
	//player.setOutlineColor(sf::Color::Green);
	//player.setOutlineThickness(20);
	////player.setOrigin(50.0f, 50.0f);		//orgin is offset from the top left corner										
	//while (window.isOpen()) // without the loop the window will showup and close instantly
	//{
	//	sf::Event event;
	//	while (window.pollEvent(event))
	//	{
	//		switch (event.type)
	//		{
	//		case sf::Event::Closed: //push close button
	//			window.close();
	//			break;
	//		case sf::Event::Resized: // when you resize the screen
	//			cout << event.size.width << "  " << event.size.height << "\n";
	//			break;
	//		case sf::Event::TextEntered:
	//			printf("%c", event.text.unicode); 
	//			
	//			break;

	//		}
	//		
	//	}
	//	// it only checks wheather the key is pressed right now or not (returns bool)
	//	//top right(0,0) //bottom right(0,screen height) // top left (screen width,0) // bottom left(screen width,screen height)
	//	//this way your dragging the shape  not moving because u r drawing to the buffers so you must clear the buffer each time
	//


	//	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	//	{
	//		player.move(-0.1f, 0.0f);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	//	{
	//		player.move(0.1f, 0.0f);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	//	{
	//		player.move(0.0f, -0.1f);
	//	}
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	//	{
	//		player.move(0.0f, 0.1f);
	//	}*/
	//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	//	{
	//		// return the mouse postion relative to the screen not to the window if default fn
	//		sf::Vector2i mousepos =sf::Mouse::getPosition(window);// return the mouse postion relative to window // this fn returns vector 2i so we must store  it in vector 2i
	//	
	//		//player.setPosition(static_cast<float>(mousepos.x)-50.0f, static_cast<float>(mousepos.y)-50.0f);// ana ba3mel cast ashan el fn deh mabta5odsh 8er float wana ma3aya integer

	//		// shelt el 50 ashan hatet orgin lel shakl however law 3malt  keda lma tefta7 le window hatla2i nos shakl bas zaher wel nos el tani mesta5bi
	//		player.setPosition(static_cast<float>(mousepos.x)-(player.getSize().x)/2 , static_cast<float>(mousepos.y) - (player.getSize().y) / 2);
	//	}

	//	

	//	window.clear(); // to clear the buffer to move the shape  note: this fn can take clour for the background screen
	//	window.draw(player);
	//	window.display();
	//}
	//-----------------------------------------------------------------------------------------------------

	//sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Tutorial", sf::Style::Close| sf::Style::Resize); //Style hoa no3 el screen bey3emlha resize wala sabta wala full screen
	//int xtiles = 500 / 20, ytiles = 500 / 20;
	//vector<sf::RectangleShape> tiles(xtiles* ytiles);
	//for (int i = 0; i < xtiles; i++)
	//{
	//	for (int j = 0; j < ytiles; j++)
	//	{
	//		tiles[i * xtiles + j].setSize(sf::Vector2f(20.0f, 20.0f));
	//		tiles[i * xtiles + j].setPosition(i * 20, j * 20);
	//		tiles[i * xtiles + j].setFillColor(sf::Color::Blue);
	//		tiles[i * xtiles + j].setOutlineThickness(4);
	//		tiles[i * xtiles + j].setOutlineColor(sf::Color::Green);

	//	}
	//}
	//sf::Event event;
	//while (window.isOpen() )

	//{
	//	while (window.pollEvent(event))
	//	{
	//		switch (event.type)
	//		{
	//			
	//						case sf::Event::Closed: //push close button
	//							window.close();
	//							break;
	//						case sf::Event::Resized: // when you resize the screen
	//							cout << event.size.width << "  " << event.size.height << "\n";
	//							break;
	//						case sf::Event::TextEntered:
	//							printf("%c", event.text.unicode); 
	//							
	//							break;

	//						
	//		}
	//	}
	//	for (int i = 0; i < xtiles * ytiles; i++)
	//	{
	//		window.draw(tiles[i]);
	//	}
	//	window.display();

	//}

//------------------------------------------------------------------------------------------------

Application a1(500, 500, 20);


}