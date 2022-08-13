#ifndef p4
#define p4
#include <vector>
#include "Cell.h"
#include "Person.h"
class Game {
	private:
		int size;
		vector<vector<Cell>> board;
		int current_x;
		int current_y;
		Person *winner;
	public: 
		Game();
		Game(int size, vector<vector<Cell>> board, int current_x, int current_y, Person* winner);
		Game(Game &game);
		~Game();
		bool check_win(); // check 3 o tiep
		void add_stone(int x, int y);
		// board[i][j].set_value('x');
		void render(); //
		
		
};
#endif