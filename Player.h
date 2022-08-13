#ifndef p2
#define p2
#include "Person.h"

class Player: public Person {
	private:
		string name; //ten nguoi choi
		string password; // mat khau
		int ID; //id nguoi choi
	public:
		Player();
		Player(int pos_x, int pos_y, string name, string password, int ID);    
		string get_name();   
		string get_password();
		int get_ID();   
		void set_name(string name);
		void set_password(string password);
		void set_ID(int ID);
		Person *clone();    

};
#endif