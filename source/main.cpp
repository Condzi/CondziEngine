#include "Engine/Util/Game.hpp"
#include <SFML/System/Err.hpp>
#include "Demo/PlayState.hpp"

int main()
{
	sf::err().rdbuf(0);

	ce::Game game(sf::Vector2u(1280, 720), "Conine Demo", 60);

	game.AddState<demo::PlayState>((int)demo::State::Play, "data/PLAY.config");
	game.Run();

	return 0;
}