#include <SFML/System/Err.hpp>
#include "Engine/Util/Game.hpp"
#include "Engine/Util/Random.hpp"
//#include "Engine/Managing/ResourceCache.hpp"
#include "Engine/Managing/CustomResourceCache.hpp"
#include "Engine/Entity/Entity.hpp"
#include "Engine/Entity/EntityHolder.hpp"
#include "Pong/States/PlayState.hpp"


class A :
	public ce::Component
{
public:
	A() {}

};

int main()
{
	try
	{
		ce::Game game(sf::Vector2u(1280, 720), "Conine", 60);
		game.AddState<PlayState>(0, "resources/playState.config");

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