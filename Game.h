#ifndef p4
#define p4
#include <vector>
#include "Cell.h"
#include "Person.h"
class Game {
	public:
		Person *character1, *character2; //character1 luon di truoc va danh x
		int size;
		vector<vector<Cell>> board;
		int current_x; // vi tri cua nuoc co vua duoc danh
		int current_y;
		Person *winner;
	
		Game();
		Game(int size, Person *character1, Person *character2);
		Game(int size);
		Game(const Game& game);
		~Game();
		int get_x() const; //
		int get_y() const;
		void set_x(int x);      
		void set_y(int y);
		int check_win(); // if equal -1, mean game does not finish, if 0, game ties, else game has 1 winner
		void add_stone(int x, int y);
		// board[i][j].set_value('x');
		void render(); //
		void finish_game(); // thuc hien cac hanh dong set up lai truoc khi game ket thuc
		void set_winner();
		void print_data();
	   	
		
};

#endif
