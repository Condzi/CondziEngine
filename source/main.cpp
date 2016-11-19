#include <SFML/System/Err.hpp>
#include "Engine/Util/Game.hpp"
#include "Engine/Util/Random.hpp"
//#include "Engine/Managing/ResourceCache.hpp"
#include "Engine/Managing/CustomResourceCache.hpp"
//#include "Pong/States/PlayState.hpp"


class C
{
public:
	C() {}

	bool LoadFromFile(std::string a) { return true; }
};
int main()
{
	try
	{
		////for (unsigned i = 0; i < 100; ++i)
		////{
		////	std::cout << ce::Random::Value(-10.f, 10.f);
		////	std::cin.get();
		////}

		sf::err().rdbuf(0);
		
		ce::CustomResourceCache<C> custom("data/", "TEST");
		C c;
		custom.Add(c, "pupa");
		custom.Get("pupa");

		std::cin.get();	

		//ce::Game game(sf::Vector2u(1280, 720), "Conine", 60);
		//game.AddState(0, new PlayState("resources/playState.config"));
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