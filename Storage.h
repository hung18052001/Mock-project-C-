#ifndef p8
#define p8
#include "Game.h"
#include "Player.h"
class Storage {
	private:
		vector<Game> list_game;
		vector<Player*> list_user;
	public:
		Storage();
		~Storage();
		void add_user(Player *user);
		void remove_user(int ID); 
		void print_user_info();
		void print_game_info();   
		void add_game(Game game);
		Player *exist_user(string name, string password);
};
#endif