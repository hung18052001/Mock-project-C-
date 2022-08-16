#include <iostream>
#include "Game.cpp"
#include "Player.cpp"
#include "Person.cpp"
#include "Storage.cpp"

using namespace std;

int main() {
    Person *c[2];
    c[0] = NULL;
    c[1] = NULL;
    
    
    Storage storage;
    string inp_name;
    string inp_password;    
    int inp_ID = 1;  

    cout << "Chào mừng bạn đã đến với game cờ caro PvP.\n";
    while(1) {
        cout << "Nhập 1 để đăng ký, nhập 2 để đăng nhập.\n";
        int selection = 0;
        cout << "Mời nhập lựa chọn: ";
        cin >> selection;  
        if (selection == 1) {
            cout << "Mời nhập tên người dùng: ";   
            fflush(stdin);   
            getline(cin, inp_name); 
            cout << "Mời nhập mật khẩu: ";   
            getline(cin, inp_password);
            storage.add_user(new Player(inp_name, inp_password, inp_ID++));
            continue;



        }
        cout << "Mời 2 người chơi đăng nhập.\n";
        for (int i = 1; i <= 2; i++) {
            while (1) {
                cout << "Mời người chơi thứ " << i << " đăng nhập.\n";
                cout << "Nhập tên: ";
                fflush(stdin);
                getline(cin, inp_name);
                cout << "Nhập mật khẩu: ";
                getline(cin, inp_password);
                Player *find_player = storage.exist_user(inp_name, inp_password);
                if (find_player == NULL) {
                    cout << "Tên đăng nhập hoặc mật khẩu không tồn tại.\n";
                    continue;
                }
                cout << "Người chơi thứ " << i << " đăng nhập thành công.\n";
                c[i - 1] = new Player(*find_player);
                break;
            }

        }
        Game game(10, c[0], c[1]);
        int turn = 1;
        int x, y;
        while(1) {
            cout << "Mời người chơi thứ " << (turn % 2) << " nhập tọa độ quân cờ: ";
            cin >> x >> y;
            game.add_stone(x, y);
            game.render();
            if (game.check_win() == -1) 
                continue;
            game.set_winner();
            game.finish_game();  
            storage.add_game(game);
            break;
        }
        storage.print_game_info();
        storage.print_user_info();
        storage.remove_user(1);
        storage.remove_user(3);


    }
    
}


