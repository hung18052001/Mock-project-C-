#include "GamePvP.h"

GamePvP::GamePvP(): 
    Game(), player1(), player2() {}
GamePvP::GamePvP(int size, vector<vector<Cell>> board, int current_x, int current_y, Person* winner, Player player1, Player player2):
    Game(size, board, current_x, current_y, winner), player1(player1), player2(player2) {}