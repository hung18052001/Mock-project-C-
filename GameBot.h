#ifndef p7
#define p7
#include "Game.h"
#include "Bot.h"
#include "Player.h"
class GameBot: public Game {
	private:
		Player player;
		Bot bot;	

};
#endif