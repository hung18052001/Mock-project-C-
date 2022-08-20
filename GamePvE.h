#ifndef p11
#define p11
#include "Game.h"
#include "Player.h"
#include "Bot.h"
class GamePvE: public Game {
	public:
		GamePvE();
		GamePvE(int size, Person *character1, Person *character2);
		GamePvE(int size);
		Game *clone();
		void play();	
};
#endif
