#include <SFML/System/Err.hpp>
#include "Engine/Util/Game.hpp"
#include "Engine/Util/Utility.hpp"
#include "Pong/States/PlayState.hpp"


int main()
{
	try
	{
		ce::random::SetSeed(time(0));
	
		for (unsigned i = 0; i < 100; ++i)
		{
			std::cout << ce::random::GetValue(-10, 10);
			std::cin.get();
		}

		////sf::err().rdbuf(0);

		//PlayState ps("resources/playState.config");
		////PlayState ps("");

		//ce::Game game;
		//game.AddState(1, &ps);
		//
		//game.Run();
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