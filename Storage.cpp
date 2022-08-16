#include "Storage.h"   
Storage::Storage() {
    list_game.resize(0);
    list_user.resize(0);
}

Storage::~Storage() {
    for (int i = 0; i < list_user.size(); i++)
        if (list_user[i] != NULL) {
            delete list_user[i];   
            list_user[i] = NULL;
        }
    
}

void Storage::add_user(Player *user) {
    list_user.push_back(user);
}

void Storage::remove_user(int ID) {
    bool check_user = false; // true if it exists ID in list
    for (int i = 0; i < list_user.size(); i++)
        if (list_user[i]->get_ID() == ID) {
            cout << "Tìm thấy ID cần xóa.\n";
            cout << "Đã xóa user " << list_user[i]->get_name() << endl;

            delete list_user[i];
            list_user[i] = NULL;  
            list_user.erase(list_user.begin() + i);
            check_user = true;    
            break;

        }
    if (!check_user)
        cout << "Không tìm thấy ID cần xóa.\n";            
}

void Storage::print_user_info() {
    cout << "Thông tin các người dùng đã đăng ký:\n";
    for (int i = 0; i < list_user.size(); i++) {
        cout << "\nNgười dùng thứ " << i + 1 << ":\n";
        list_user[i]->print_info();
    }
}
void Storage::add_game(Game game) {
    
    list_game.push_back(game);

}
void Storage::print_game_info() {
    cout << "Thông tin các ván đấu đã diễn ra:\n";
    for (int i = 0; i < list_game.size(); i++) {
        cout << "\nVán đấu thứ " << i + 1 << ":\n";  
        list_game[i].print_data();
    }
}

Player *Storage::exist_user(string name, string password) {
    for (int i = 0; i < list_user.size(); i++) 
        if (list_user[i]->get_name() == name && list_user[i]->get_password() == password)
            return list_user[i];   
    return NULL;
}
