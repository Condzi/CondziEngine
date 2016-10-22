#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Managing/ResourceManager.hpp"
#include <iostream>
#include <memory>

int main()
{
	try
	{
		sf::err().rdbuf(0);

		ce::ErrorCode::ResourceManager rm = ce::ErrorCode::ResourceManager::NONE;
		ce::ResourceManager res("rsrc/Resources.config", &rm);
		sf::Sprite spr;
		sf::Text text;
		spr.setTexture(res.GetTexture("SAMPLE_1"));
		text.setFont(res.GetFont("SAMPLE_1"));
		text.setString("zmienny");

		sf::RenderWindow win(sf::VideoMode(800, 600), "Condzi Engine", sf::Style::Close);
		win.setFramerateLimit(30);
		sf::Event ev;

		while (win.isOpen())
		{
			while (win.pollEvent(ev))
			{
				if (ev.type == sf::Event::Closed)
				{
					win.close();
				}
			}

			win.clear();
			win.draw(spr);
			win.draw(text);
			win.display();
		}
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what();
		std::cin.get();
	}


	return 0;
}