#include "GamePvE.h"
#include <cstdlib>
#include <math.h>


GamePvE::GamePvE(): 
    Game() {}
GamePvE::GamePvE(int size, Person *character1, Person *character2):
    Game(size, character1, character2) {}
GamePvE::GamePvE(int size):
    Game(size) {}

Game *GamePvE::clone() {
    return new GamePvE(*this);
}

void GamePvE::play() {
    int mode; 
    cout << "Nhập 1 để chọn mức dễ.\n";
    cout << "Nhập 2 để chọn mức khó.\n";
    cout << "Xin mời nhập lựa chọn : ";
    cin >> mode;
    Person *player1, *player2;   
    player1 = get_character1();
    player2 = get_character2();
    if (mode == 1) player2->set_name("Easy bot");
    else player2->set_name("Hard bot");
    int turn = 1;
    int random_value;
    bool character1_first = random_value == 0 ? true : false;
    if (mode == 2){
        while (1) {
            if ((turn + random_value) % 2 == 1) {
                cout << "Mời " << player1->get_name() << " nhập tọa độ quân cờ: ";
                int x, y;   
                cin >> x >> y;    
                if (check_point(x,y) == false){
                    do {
                        cout << "\nTọa độ vừa nhập đã bị trùng !!! " << endl;
                        cout << "Mời " << player1->get_name() <<" nhập lại tọa độ quân cờ: ";
                        cin >> x >> y;
                    }while (check_point(x,y) == false);
                }
                add_stone(x, y, turn + random_value);
                render();
            } 
            else {
                cout << "Đến lượt " << player2->get_name() << " đánh:\n";
                int x, y;
                x = Tim_Kiem_NuocDi_1().get_x();
                y = Tim_Kiem_NuocDi_1().get_y();
                cout << x << " " << y << endl;
                add_stone(x, y, turn + random_value);
                cout << endl;
                render();
            }
            turn ++;
            if (check_win() == -1) continue;
            set_winner();
            finish_game();
            break;
        }
    }
    else {
        while (1) {
            if (turn % 2 == 1) {
                cout << "Mời " << player1->get_name() << " nhập tọa độ quân cờ: ";
                int x, y;   
                cin >> x >> y;
                if (check_point(x,y) == false){
                    do {
                        cout << "\nTọa độ vừa nhập đã bị trùng !!! " << endl;
                        cout << "Mời " << player1->get_name() <<" nhập lại tọa độ quân cờ: ";
                        cin >> x >> y;
                    }while (check_point(x,y) == false);
                }  
                add_stone(x, y, turn + random_value);
                render();
            } 
            else {
                cout << "Đến lượt " << player2->get_name() << " đánh:\n";
                int x, y;
                x = Tim_Kiem_NuocDi_2().get_x();
                y = Tim_Kiem_NuocDi_2().get_y();
                cout << x << " " << y << endl;
                add_stone(x, y, turn + random_value);
                cout << endl;
                render();
            }
            turn ++;
            if (check_win() == -1) continue;
            set_winner();
            finish_game();
            break;
        }
    }    
}