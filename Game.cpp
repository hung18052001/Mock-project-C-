#include "Game.h"

Game::Game(): 
    size(0), current_x(-1), current_y(-1), winner(NULL) {
    board.resize(0);
}
Game::Game(int size):
    size(size), current_x(-1), current_y(-1), winner(NULL) { // vi game vua moi tao, nen chua co nuoc nao duoc danh, cung co nghia khong ton tai current_x hay current_y
    board = vector<vector<Cell>>(size, vector<Cell>(size));
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

bool Game::check_win(int x, int y) {
    int size = board.size();
    int count = 0;
    int temp = 1;
    int i = 1;
    while (y - i >= 0 && board[x][y - i] == board[x][y]) {
        temp++;
        i++;
    }
    i = 1;
    while (y + i <= size - 1 && board[x][y + i] == board[x][y]) {
        temp++;
        i++;
    }

    temp = 1;
    i = 1;
    while (x - i >= 0 && board[x - i][y] == board[x][y]) {
        temp++;
        i++;
    }
    i = 1;
    while (x + i <= size - 1 && board[x + i][y] == board[x][y]) {
        temp++;
        i++;
    }
    if (temp >= 4) count++;

    temp = 1;
    i = 1;
    while (x - i >= 0 && y - i >= 0 && board[x - i][y - i] == board[x][y]) {
        temp++;
        i++;
    }
    i = 1;
    while (x + i <= size - 1 && y + i <= size - 1 && board[x + i][y + i] == board[x][y]) {
        temp++;
        i++;
    }
    if (temp >= 4) count++;

    temp = 1;
    i = 1;
    while (x - i >= 0 && y - i >= 0 && board[x - i][y - i] == board[x][y]) {
        temp++;
        i++;
    }
    i = 1;
    while (x + i <= size - 1 && y + i <= size - 1 && board[x + i][y + i] == board[x][y]) {
        temp++;
        i++;
    }
    if (temp >= 4) count++;

    return count > 0;
}

void Game::add_stone(int x, int y) {
	static int turnCount = 1;
	board[x][y].set_value((x % 2 != 0) ? "X" : "O");
    turnCount++;
}

void Game::render() {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << board[i][j].get_value() << '\n';
        }
        cout << '\n';
    }
}

void Game::update(int x, int y) {
    board.at(x - 1).at(y - 1).set_value("X");
}
