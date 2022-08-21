#include "GamePvP.h"
#include <cstdlib>


GamePvP::GamePvP(): 
    Game() {}
GamePvP::GamePvP(int size, Person *character1, Person *character2):
    Game(size, character1, character2) {}
GamePvP::GamePvP(int size):
    Game(size) {}

<<<<<<< HEAD



=======
>>>>>>> sonth
Game *GamePvP::clone() {
    return new GamePvP(*this);
}

void GamePvP::play() {
    cout << "Tiến hành chọn ngẫu nhiên: ";
    int random_value = rand() % 2; // if 0, player1 goes first, else player2 goes first.
    Person *player1, *player2;   
    if (random_value == 0) {
        player1 = get_character1();
        player2 = get_character2();   
    }
    else {
        player1 = get_character2();
        player2 = get_character1();    
    }
    cout << player1->get_name() << " đi trước.\n";
    bool character1_first = random_value == 0 ? true : false;
    int turn = 1;
    while (1) {
        if (turn % 2 == 1) 
            cout << "Mời " << player1->get_name() << " nhập tọa độ quân cờ: ";
        else cout << "Mời " << player2->get_name() << " nhập tọa độ quân cờ: ";
        int x, y;   
        cin >> x >> y;    
<<<<<<< HEAD
        add_stone(x, y, character1_first);
        render();
        turn ++;
        if (check_win() == -1) continue;
        set_winner();  
        finish_game();
        break;
    }


}

=======
        if (check_point(x,y) == false){
            do {
                cout << "\nTọa độ vừa nhập đã bị trùng !!! " << endl;
                cout << "Mời " << player1->get_name() <<" nhập lại tọa độ quân cờ: ";
                cin >> x >> y;
            }while (check_point(x,y) == false);
        }
        add_stone(x, y, turn + random_value);
        render();
        turn ++;
        if (check_win() == -1) continue;
        set_winner();
        finish_game();
        break;
    }
}
>>>>>>> sonth
