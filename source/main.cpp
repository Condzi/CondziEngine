#include <SFML/System/Err.hpp>
#include "Engine/Util/Game.hpp"


int main()
{
	sf::err().rdbuf(0);

	ce::Game game(sf::Vector2u(1280, 720), "Conine", 60);

	game.Run();

	return 0;
}