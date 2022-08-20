#ifndef p4
#define p4
#include <vector>
#include "Cell.h"
#include "Person.h"

const int Defend_Score1[7] = { 0, 3, 24, 243, 2197, 19773, 177957 };
const int Attack_Score1[7] = { 0, 4, 25, 246, 7300, 6561, 59049 };
// 2 mảng điểm tấn công phòng thủ cho máy khó
const int Defend_Score2[7] = { 0, 1, 9, 81, 729, 6561, 59049  }; 
const int Attack_Score2[7] = { 0, 4, 25, 246, 7300, 6561, 59049}; 
// 2 mảng điểm tấn công phòng thủ cho máy dễ

class Point{
	private:
		int x;
		int y;
	public:
		void setX(int X){
			x = X;
		}
		void setY(int Y){
			y = Y;
		}
		int getX(){
			return x;
		}
		int getY(){
			return y;
		}
};

class Game {
	private:
		Person *character1, *character2; //character1 luon di truoc va danh x
		int size;
		vector<vector<Cell>> board;
		int current_x; // vi tri cua nuoc co vua duoc danh
		int current_y;
		Person *winner;
	public: 
		Game();
		Game(int size, Person *character1, Person *character2);
		Game(int size, Person *character);
		Game(int size);
		Game(const Game& game);
		~Game();
		void set_size(int size);
		Person *get_character1();
		Person *get_character2();

		void set_character1(Person *character1);
		void set_character2(Person *character2);
		int get_x() const; //
		int get_y() const;
		void set_x(int x);      
		void set_y(int y);
		int check_win(); // if equal -1, mean game does not finish, if 0, game ties, else game has 1 winner
		void add_stone(int x, int y, int turnCount);
		// board[i][j].set_value('x');
		void render(); //
		void finish_game(); // thuc hien cac hanh dong set up lai truoc khi game ket thuc
		void set_winner();
		void print_data();
		
		virtual void play();
		void play_(int mode);
		virtual Game *clone();

		bool Cattia(int i, int j);
		bool catTiaNgang(int i, int j);
		bool catTiaDoc(int i, int j);
		bool catTiaCheoPhai(int i, int j);
		bool catTiaCheoTrai(int i, int j);

		Game Tim_Kiem_NuocDi_1(); // Tìm nước đi cho máy khó
		Game Tim_Kiem_NuocDi_2(); // Tìm nước đi cho máy dễ
		int SoDiemTanCong_DuyetDoc(int, int, const int Defend_Score[], const int Attack_Score[]);
		int SoDiemTanCong_DuyetNgang(int, int, const int Defend_Score[], const int Attack_Score[]);
		int SoDiemTanCong_DuyetCheo1(int, int, const int Defend_Score[], const int Attack_Score[]);
		int SoDiemTanCong_DuyetCheo2(int, int, const int Defend_Score[], const int Attack_Score[]);
		int SoDiemPhongThu_DuyetDoc(int, int, const int Defend_Score[], const int Attack_Score[]);
		int SoDiemPhongThu_DuyetNgang(int, int, const int Defend_Score[], const int Attack_Score[]);
		int SoDiemPhongThu_DuyetCheo1(int, int, const int Defend_Score[], const int Attack_Score[]);
		int SoDiemPhongThu_DuyetCheo2(int, int, const int Defend_Score[], const int Attack_Score[]);
	   		
};
#endif
