#ifndef p8
#define p8
#include "Game.h"
#include "Player.h"
#include <fstream>
class Storage {
	private:
		vector<Game> list_game;
		vector<Player*> list_user;
		vector<Player*> list_admin;
	public:
		Storage();
		~Storage();
		void add_user(Player *user);
		void remove_user(string name); 
		void add_admin(Player *admin);   
		void remove_admin(string name);
		void print_user_info();
		void print_game_info();   
		void print_admin_info();
		void add_game(Game *game);
		Player *exist(string name, string password, bool is_admin);
		void read_admin_info_from_txt(string file);
		void read_user_info_from_txt(string file);
		void save_admin_info_to_txt(string file);
		void save_user_info_to_txt(string file);
		int last_ID();
		void clear_game();

		
};
#endif