#include "Game.h"

Game::Game(): 
    size(0), current_x(-1), current_y(-1), winner(NULL), character1(NULL), character2(NULL) {
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

Game::Game(int size, Person *character1, Person *character2):
    size(size), current_x(-2), current_y(-2), winner(NULL) {
    board.resize(size);
    for (int i = 0; i < size; i++)  
        board[i].resize(size);    
    for (int i = 0; i < size; i++) 
        for (int j = 0; j < size; j++)   
            board[i][j].set_value(" ");
    this->character1 = character1;
    this->character2 = character2;     
}

Game::Game(const Game& game):
    current_x(game.get_x()), current_y(game.get_y()) {
    size = game.size;
    board.resize(size);
    for (int i = 0; i < size; i++)  
        board[i].resize(size);  

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j].set_value(game.board[i][j].get_value());
            cout << board[i][j].get_value() << " ";

        }
        cout << endl;
    }

    winner = game.winner->clone();
    character1 = game.character1->clone();
    character2 = game.character2->clone();
}

Game::~Game() {
    if (winner != NULL) {
        delete winner;   
        winner = NULL;
    }
}

int Game::get_x() const {
    return current_x;
}
int Game::get_y() const {
    return current_y;
}
void Game::set_x(int x) {
    current_x = x;
}

void Game::set_y(int y) {
    current_y = y;
}
int Game::check_win() {
    // kiem tra dieu kien hoa
    bool is_tie = true;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) 
            if (board[i][j].get_value() == " ") {
                is_tie = false;
                break;
            }
    if (is_tie) return 0;
    int count = 0;
    int temp = 1;
    int i = 1;
    while (current_y - i >= 0 && board[current_x][current_y - i].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    i = 1;
    while (current_y + i <= size - 1 && board[current_x][current_y + i].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    if (temp >= 4) count++;

    temp = 1;
    i = 1;
    while (current_x - i >= 0 && board[current_x - i][current_y].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    i = 1;
    while (current_x + i <= size - 1 && board[current_x + i][current_y].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    if (temp >= 4) count++;

    temp = 1;
    i = 1;
    while (current_x - i >= 0 && current_y - i >= 0 && board[current_x - i][current_y - i].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    i = 1;
    while (current_x + i <= size - 1 && current_y + i <= size - 1 && board[current_x + i][current_y + i].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    if (temp >= 4) count++;

    temp = 1;
    i = 1;
    while (current_x - i >= 0 && current_y - i >= 0 && board[current_x - i][current_y - i].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    i = 1;
    while (current_x + i <= size - 1 && current_y + i <= size - 1 && board[current_x + i][current_y + i].get_value() == board[current_x][current_y].get_value()) {
        temp++;
        i++;
    }
    if (temp >= 4) count++;

    return count > 0 ? 1 : -1;
}

void Game::add_stone(int x, int y) {
	static int turnCount = 1;
    current_x = x;
    current_y = y;
    if (turnCount % 2 == 1) {
        character1->set_pos_x(x);
        character1->set_pos_y(y);
        board[x][y].set_value("x");
    }
    else {
        character2->set_pos_x(x);    
        character2->set_pos_y(y);
        board[x][y].set_value("o");
    }
	turnCount++;
}


void Game::finish_game() {
    character1->set_pos_x(-1);
    character1->set_pos_y(-1);
    character2->set_pos_x(-1);
    character2->set_pos_y(-1);
}

void Game::set_winner() {
    
    int win_num = 0; // 1 if character1 win else 2
    cout << "Trò chơi kết thúc." << endl;     
    if (check_win() == 0)
        cout << "Kết quả chung cuộc: Hòa!!!";    
    else {
        if (board[current_x][current_y].get_value() == "x") {
            cout << "Kết quả chung cuộc: " << character1->get_name() << " dành chiến thắng!!!" << endl;
            winner = character1;
        }
        else {
            cout << "Kết quả chung cuộc: " << character2->get_name() << " dành chiến thắng!!!" << endl;
            winner = character2;
        }
    }  
    
    
    

    
}


void Game::render() {
	
	//draw board
	
	int axisX = 0, axisY = 0;  // these variables just used to print with board
	cout << " ";
	for(int j = 0; j < size * 4; j++){
		if(j == 2 || (j - 2) % 4 == 0)
			cout << axisX++;
		else
			cout << " ";
	}
	cout << endl;
	
	//draw cell boxs in each row
	int x_console = 0, y_console = -1; // two coordinates made to print on console
	for(int i = 0; i < size; i++){
		cout << " ";
		for(int j = 0; j < size * 4; j++){
			if(j % 4 == 0)
				cout << char(43);
			else
				cout << char(45);
		}
		cout << char(43) << endl;
		
		cout << " ";
		for(int j = 0; j < size * 4; j++){
			if(j % 4 == 0){
				cout << char(124);
				++y_console;
			}
			else if(j == 2 || (j - 2) % 4 == 0){
				cout << board[x_console][y_console].get_value();
			}
			else
				cout << " ";
		}
		cout << char(124) << " " << axisY++ << endl;
		x_console++;
		y_console = -1;
	}
	
	//draw last edge of board
	cout << " ";
	for(int j = 0; j < size*4; j++){
		if(j % 4 == 0)
			cout << char(43);
		else
			cout << char(45);
	}
	cout << char(43) << endl;

	
}

void Game::print_data() {
    cout << "Các nhân vật tham gia trò chơi: ";    
    cout << character1->get_name() << ", " << character2->get_name() << "\n";
    cout << "Kết quả trò chơi: ";
    if (check_win() == 0)
        cout << "Hòa.\n";
    else cout << winner->get_name() << " dành chiến thắng.\n";
}