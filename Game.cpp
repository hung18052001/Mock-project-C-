#include "Game.h"
#include <string.h>
#include "GamePvE.h"

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
        }
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

void Game::set_size(int size) {
    this->size = size;
    board.resize(size);
    for (int i = 0; i < size; i++) 
        board[i].resize(size);
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j].set_value(" ");
}
Person *Game::get_character1() {
    return character1;
}

Person *Game::get_character2() {
    return character2;
}
void Game::set_character1(Person *character1) {
    this->character1 = character1;
}

void Game::set_character2(Person *character2) {
    this->character2 = character2;
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

bool Game::check_point(int row, int col)
{
    if (board[row][col].get_value() == "x" || board[row][col].get_value() == "o" ){
        return false;
    }
    else {
        return true;
    }
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
    if (temp >= 5) count++;

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
    if (temp >= 5) count++;

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
    if (temp >= 5) count++;

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
    if (temp >= 5) count++;

    return count > 0 ? 1 : -1;
}

void Game::add_stone(int x, int y, int turnCount) {
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

void Game::play() {

}

Game *Game::clone() {
    return NULL;
}

int Game::SoDiemTanCong_DuyetNgang(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemTanCong = 0;
    int SoQuanTa = 0;
    int SoQuanDichPhai = 0;
    int SoQuanDichTrai = 0;
    int KhoangChong = 0;

    //bên phải
    for (int dem = 1; dem <= 4 && col < size - 5; dem++)
    {
        if (board[row][col + dem].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;
        }
        else
            if (board[row][col + dem].get_value() == "x")
            {
                SoQuanDichPhai++;
                break;
            }
            else KhoangChong++;
    }
    //bên trái
    for (int dem = 1; dem <= 4 && col > 4; dem++)
    {
        if (board[row][col - dem].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;
        }
        else
            if (board[row][col - dem].get_value() == "x")
            {
                SoQuanDichTrai++;
                break;
            }
            else KhoangChong++;
    }
    //bị chặn 2 đầu khoảng chống không đủ tạo thành 4 nước
    if (SoQuanDichPhai > 0 && SoQuanDichTrai > 0 && KhoangChong < 3)
        return 0;

    DiemTanCong -= Defend_Score[SoQuanDichPhai + SoQuanDichTrai];
    DiemTanCong += Attack_Score[SoQuanTa];
    return DiemTanCong;
}

//duyệt dọc
int Game::SoDiemTanCong_DuyetDoc(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemTanCong = 0;
    int SoQuanTa = 0;
    int SoQuanDichTren = 0;
    int SoQuanDichDuoi = 0;
    int KhoangChong = 0;

    //bên trên
    for (int dem = 1; dem <= 4 && row > 4; dem++)
    {
        if (board[row - dem][col].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;

        }
        else
            if (board[row - dem][col].get_value() == "x")
            {
                SoQuanDichTren++;
                break;
            }
            else KhoangChong++;
    }
    //bên dưới
    for (int dem = 1; dem <= 4 && row < size - 5; dem++)
    {
        if (board[row + dem][col].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;

        }
        else
            if (board[row + dem][col].get_value() == "x")
            {
                SoQuanDichDuoi++;
                break;
            }
            else KhoangChong++;
    }
    //bị chặn 2 đầu khoảng chống không đủ tạo thành 4 nước
    if (SoQuanDichTren > 0 && SoQuanDichDuoi > 0 && KhoangChong < 3)
        return 0;

    DiemTanCong -= Defend_Score[SoQuanDichTren + SoQuanDichDuoi];
    DiemTanCong += Attack_Score[SoQuanTa];
    return DiemTanCong;
}

//chéo xuôi
int Game::SoDiemTanCong_DuyetCheo1(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemTanCong = 1;
    int SoQuanTa = 0;
    int SoQuanDichCheoTren = 0;
    int SoQuanDichCheoDuoi = 0;
    int KhoangChong = 0;

    //bên chéo xuôi xuống
    for (int dem = 1; dem <= 4 && col < size - 5 && row < size - 5; dem++)
    {
        if (board[row + dem][col + dem].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;
        }
        else
            if (board[row + dem][col + dem].get_value() == "x")
            {
                SoQuanDichCheoTren++;
                break;
            }
            else KhoangChong++;
    }
    //chéo xuôi lên
    for (int dem = 1; dem <= 4 && row > 4 && col > 4; dem++)
    {
        if (board[row - dem][col - dem].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;

        }
        else
            if (board[row - dem][col - dem].get_value() == "x")
            {
                SoQuanDichCheoDuoi++;
                break;
            }
            else KhoangChong++;
    }
    //bị chặn 2 đầu khoảng chống không đủ tạo thành 4 nước
    if (SoQuanDichCheoTren > 0 && SoQuanDichCheoDuoi > 0 && KhoangChong < 3)
        return 0;

        DiemTanCong -= Defend_Score[SoQuanDichCheoTren + SoQuanDichCheoDuoi];
        DiemTanCong += Attack_Score[SoQuanTa];
    return DiemTanCong;
}

//chéo ngược
int Game::SoDiemTanCong_DuyetCheo2(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemTanCong = 0;
    int SoQuanTa = 0;
    int SoQuanDichCheoTren = 0;
    int SoQuanDichCheoDuoi = 0;
    int KhoangChong = 0;

    //chéo ngược lên
    for (int dem = 1; dem <= 4 && col < size - 5 && row > 4; dem++)
    {
        if (board[row - dem][col + dem].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;
        }
        else
            if (board[row - dem][col + dem].get_value() == "x")
            {
                SoQuanDichCheoTren++;
                break;
            }
            else KhoangChong++;
    }
    //chéo ngược xuống
    for (int dem = 1; dem <= 4 && col > 4 && row < size - 5; dem++)
    {
        if (board[row + dem][col - dem].get_value() == "o")
        {
            if (dem == 1)
                DiemTanCong += 37;

            SoQuanTa++;
            KhoangChong++;

        }
        else
            if (board[row + dem][col - dem].get_value() == "x")
            {
                SoQuanDichCheoDuoi++;
                break;
            }
            else KhoangChong++;
            }
    //bị chặn 2 đầu khoảng chống không đủ tạo thành 4 nước
    if (SoQuanDichCheoTren > 0 && SoQuanDichCheoDuoi > 0 && KhoangChong < 3)
        return 0;

    DiemTanCong -= Defend_Score[SoQuanDichCheoTren + SoQuanDichCheoDuoi];
    DiemTanCong += Attack_Score[SoQuanTa];
    return DiemTanCong;
}

//duyệt ngang
int Game::SoDiemPhongThu_DuyetNgang(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemPhongNgu = 0;
    int SoQuanTaTrai = 0;
    int SoQuanTaPhai = 0;
    int SoQuanDich = 0;
    int KhoangChongPhai = 0;
    int KhoangChongTrai = 0;
    bool ok = false;

    for (int dem = 1; dem <= 4 && col < size - 5; dem++)
    {
        if (board[row][col + dem].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;
        }
        else
            if (board[row][col + dem].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaTrai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongPhai++;
            }
    }

    if (SoQuanDich == 3 && KhoangChongPhai == 1 && ok)
        DiemPhongNgu -= 200;

    ok = false;

    for (int dem = 1; dem <= 4 && col > 4; dem++)
    {
        if (board[row][col - dem].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;
        }
        else
            if (board[row][col - dem].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaPhai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongTrai++;
            }
    }

    if (SoQuanDich == 3 && KhoangChongTrai == 1 && ok)
        DiemPhongNgu -= 200;

    if (SoQuanTaPhai > 0 && SoQuanTaTrai > 0 && (KhoangChongTrai + KhoangChongPhai + SoQuanDich) < 4)
        return 0;

    DiemPhongNgu -= Attack_Score[SoQuanTaPhai + SoQuanTaPhai];
    DiemPhongNgu += Defend_Score[SoQuanDich];

    return DiemPhongNgu;
}

//duyệt dọc
int Game::SoDiemPhongThu_DuyetDoc(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemPhongNgu = 0;
    int SoQuanTaTrai = 0;
    int SoQuanTaPhai = 0;
    int SoQuanDich = 0;
    int KhoangChongTren = 0;
    int KhoangChongDuoi = 0;
    bool ok = false;

    //lên
    for (int dem = 1; dem <= 4 && row > 4; dem++)
    {
        if (board[row - dem][col].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;

        }
        else
            if (board[row - dem][col].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaPhai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongTren++;
            }
    }

    if (SoQuanDich == 3 && KhoangChongTren == 1 && ok)
        DiemPhongNgu -= 200;

    ok = false;
    //xuống
    for (int dem = 1; dem <= 4 && row < size - 5; dem++)
    {
        //gặp quân địch
        if (board[row + dem][col].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;
        }
        else
            if (board[row + dem][col].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaTrai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongDuoi++;
            }
    }

    if (SoQuanDich == 3 && KhoangChongDuoi == 1 && ok)
        DiemPhongNgu -= 200;

    if (SoQuanTaPhai > 0 && SoQuanTaTrai > 0 && (KhoangChongTren + KhoangChongDuoi + SoQuanDich) < 4)
        return 0;

    DiemPhongNgu -= Attack_Score[SoQuanTaTrai + SoQuanTaPhai];
    DiemPhongNgu += Defend_Score[SoQuanDich];
    return DiemPhongNgu;
}

//chéo xuôi
int Game::SoDiemPhongThu_DuyetCheo1(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemPhongNgu = 0;
    int SoQuanTaTrai = 0;
    int SoQuanTaPhai = 0;
    int SoQuanDich = 0;
    int KhoangChongTren = 0;
    int KhoangChongDuoi = 0;
    bool ok = false;

    //lên
    for (int dem = 1; dem <= 4 && row < size - 5 && col < size - 5; dem++)
    {
        if (board[row + dem][col + dem].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;
        }
        else
            if (board[row + dem][col + dem].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaPhai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongTren++;
            }
    }

    if (SoQuanDich == 3 && KhoangChongTren == 1 && ok)
        DiemPhongNgu -= 200;

    ok = false;
    //xuống
    for (int dem = 1; dem <= 4 && row > 4 && col > 4; dem++)
    {
        if (board[row - dem][col - dem].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;
        }
        else
            if (board[row - dem][col - dem].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaTrai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongDuoi++;
            }
    }

    if (SoQuanDich == 3 && KhoangChongDuoi == 1 && ok)
        DiemPhongNgu -= 200;

    if (SoQuanTaPhai > 0 && SoQuanTaTrai > 0 && (KhoangChongTren + KhoangChongDuoi + SoQuanDich) < 4)
        return 0;

    DiemPhongNgu -= Attack_Score[SoQuanTaPhai + SoQuanTaTrai];
    DiemPhongNgu += Defend_Score[SoQuanDich];

    return DiemPhongNgu;
}

//chéo ngược
int Game::SoDiemPhongThu_DuyetCheo2(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
    int DiemPhongNgu = 0;
    int SoQuanTaTrai = 0;
    int SoQuanTaPhai = 0;
    int SoQuanDich = 0;
    int KhoangChongTren = 0;
    int KhoangChongDuoi = 0;
    bool ok = false;

    //lên
    for (int dem = 1; dem <= 4 && row > 4 && col < size - 5; dem++)
    {

        if (board[row - dem][col + dem].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;
        }
        else
            if (board[row - dem][col + dem].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaPhai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongTren++;
            }
    }
    

    if (SoQuanDich == 3 && KhoangChongTren == 1 && ok)
        DiemPhongNgu -= 200;

    ok = false;

    //xuống
    for (int dem = 1; dem <= 4 && row < size - 5 && col > 4; dem++)
    {
        if (board[row + dem][col - dem].get_value() == "x")
        {
            if (dem == 1)
                DiemPhongNgu += 9;

            SoQuanDich++;
        }
        else
            if (board[row + dem][col - dem].get_value() == "o")
            {
                if (dem == 4)
                    DiemPhongNgu -= 170;

                SoQuanTaTrai++;
                break;
            }
            else
            {
                if (dem == 1)
                    ok = true;

                KhoangChongDuoi++;
            }
    }

    if (SoQuanDich == 3 && KhoangChongDuoi == 1 && ok)
        DiemPhongNgu -= 200;

    if (SoQuanTaPhai > 0 && SoQuanTaTrai > 0 && (KhoangChongTren + KhoangChongDuoi + SoQuanDich) < 4)
        return 0;

    DiemPhongNgu -= Attack_Score[SoQuanTaTrai + SoQuanTaPhai];
    DiemPhongNgu += Defend_Score[SoQuanDich];

    return DiemPhongNgu;
}

Game Game::Tim_Kiem_NuocDi_1()
{
    Game Pos ;
    int row=0, col=0;
    int Diem = 0;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int DiemTanCong = 0;
            int DiemPhongThu = 0;
            if (board[i][j].get_value() == " " && board[i][j].get_value() != "x" && board[i][j].get_value() != "o")
            {
                DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1,Attack_Score1);
                DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
                DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
                DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

                DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
                DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
                DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
                DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

                if (DiemTanCong > DiemPhongThu)
                {
                    if (Diem < DiemTanCong)
                    {
                        Diem = DiemTanCong;
                        row = i;
                        col = j;
                    }
                }
                else
                {
                    if (Diem < DiemPhongThu)
                    {
                        Diem = DiemPhongThu;
                        row = i;
                        col = j;
                    }
                }
            }
        }
    }
    Pos.set_x(row);
    Pos.set_y(col);
    return Pos;
}
Game Game::Tim_Kiem_NuocDi_2()
{
    Game Pos;
    int row = 0, col = 0;
    int Diem = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int DiemTanCong = 0;
            int DiemPhongThu = 0;
            if (board[i][j].get_value() == " " && board[i][j].get_value() != "x" && board[i][j].get_value() != "o" )
            {
                DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
                DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
                DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
                DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

                DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
                DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
                DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
                DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

                if (DiemTanCong > DiemPhongThu)
                {
                    if (Diem < DiemTanCong)
                    {
                        Diem = DiemTanCong;
                        row = i;
                        col = j;
                    }
                }
                else
                {
                    if (Diem < DiemPhongThu)
                    {
                        Diem = DiemPhongThu;
                        row = i;
                        col = j;
                    }
                }
            }
        }
    }
    Pos.set_x(row);
    Pos.set_y(col);
    return Pos;
}