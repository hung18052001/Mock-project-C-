#ifndef p5
#define p5
#include "Game.h"
#include "Player.h"
class GamePvP: public Game {
	public:
		GamePvP();
		GamePvP(int size, Person *character1, Person *character2);
		GamePvP(int size);
		Game *clone();
		void play();	
};
#endif
