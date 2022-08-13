#ifndef p5
#define p5
#include "Game.h"
#include "Player.h"
class GamePvP: public Game {
	private:
		Player player1; // player1 always play with x
		Player player2; // player2 always play with o
	public:
		GamePvP();
		GamePvP(int size, vector<vector<Cell>> board, int current_x, int current_y, Person* winner, Player player1, Player player2);
		

		
};
#endif
