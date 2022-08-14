#include "Game.h"

Game::Game(): 
    size(0), current_x(-1), current_y(-1), winner(NULL) {
    board.resize(0);
}
Game::Game(int size):
    size(size), current_x(-1), current_y(-1), winner(NULL) { // vi game vua moi tao, nen chua co nuoc nao duoc danh, cung co nghia khong ton tai current_x hay current_y
    board.resize(size);    
    for (int i = 0; i < size; i++)  
        board[i].resize(size);    
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++)   
            board[i][j].set_value(" ");
}

Game::Game(int size, vector<vector<Cell>> board, int x, int y, Person *winner):
    size(size), board(board), current_x(x), current_y(y) {
    this->winner = winner->clone();
}

Game::Game(Game &game):
    size(game.size), board(game.board), current_x(game.current_x), current_y(game.current_y) {
    winner = game.winner->clone();
}

Game::~Game() {
    if (winner != NULL) {
        delete winner;   
        winner = NULL;
    }
}

bool Game::check_win() {}

void Game::add_stone(int x, int y) {}

void Game::render() {}
