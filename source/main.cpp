#include <SFML/System/Err.hpp>
#include "Engine/Util/Game.hpp"


int main()
{
	try
	{
		//sf::err().rdbuf(0);

		ce::Game game;
		
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