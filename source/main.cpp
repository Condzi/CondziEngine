#include <SFML/System/Err.hpp>
#include "Engine/Util/Game.hpp"


int main()
{
	try
	{
		//sf::err().rdbuf(0);

		PlayState ps("resources/playState.config");

		ce::Game game;
		game.AddState(1, &ps);
		
		game.Run();
	}
	catch (std::runtime_error & rm)
	{
		std::cout << rm.what();
		std::cin.get();
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what();
		std::cin.get();
	}


	return 0;
}