#include "Storage.h"   
Storage::Storage() {
    list_game.resize(0);
    list_user.resize(0);
    list_admin.resize(0);
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

void Storage::remove_user(string name) {
    bool check_user = false; // true if it exists user in list
    for (int i = 0; i < list_user.size(); i++)
        if (list_user[i]->get_name() == name) {
            cout << "Tìm thấy user cần xóa.\n";
            cout << "Đã xóa user " << list_user[i]->get_name() << endl;

            delete list_user[i];
            list_user[i] = NULL;  
            list_user.erase(list_user.begin() + i);
            check_user = true;    
            break;

        }
    if (!check_user)
        cout << "Không tìm thấy user cần xóa.\n";            
}

void Storage::add_admin(Player *admin) {
    list_admin.push_back(admin);
}

void Storage::remove_admin(string name) {
    bool check_admin = false; // true if it exists admin in list
    for (int i = 0; i < list_user.size(); i++)
        if (list_admin[i]->get_name() == name) {
            cout << "Tìm thấy admin cần xóa.\n";
            cout << "Đã xóa admin " << list_admin[i]->get_name() << endl;

            delete list_admin[i];
            list_admin[i] = NULL;  
            list_admin.erase(list_admin.begin() + i);
            check_admin = true;    
            break;

        }
    if (!check_admin)
        cout << "Không tìm thấy admin cần xóa.\n";   
}

void Storage::print_user_info() {
    cout << "Thông tin các người dùng đã đăng ký:\n";
    for (int i = 0; i < list_user.size(); i++) {
        cout << "\nNgười dùng thứ " << i + 1 << ":\n";
        list_user[i]->print_info();
    }
}
void Storage::add_game(Game *game) {
    
    list_game.push_back(*game); 

}
void Storage::print_game_info() {
    cout << "Thông tin các ván đấu đã diễn ra:\n";
    for (int i = 0; i < list_game.size(); i++) {
        cout << "\nVán đấu thứ " << i + 1 << ":\n";  
        list_game[i].print_data();
    }
}

Player *Storage::exist(string name, string password, bool is_admin) {
    if (!is_admin) {
        for (int i = 0; i < list_user.size(); i++) 
            if (list_user[i]->get_name() == name && list_user[i]->get_password() == password)
                return list_user[i];   
        return NULL;
    }
    for (int i = 0; i < list_admin.size(); i++) 
        if (list_admin[i]->get_name() == name && list_admin[i]->get_password() == password)
            return list_admin[i];   
    return NULL;
    
}

void Storage::print_admin_info() {
    for (int i = 0; i < list_admin.size(); i++) {
        cout << "\nThông tin admin thứ " << i + 1 << ":\n";
        list_admin[i]->print_info();
    }
}

void Storage::read_admin_info_from_txt(string file) {
    list_admin.resize(0);
    ifstream my_file(file);
    string inp_name;
    string inp_password;
    do {
        getline(my_file, inp_name);   
        if (inp_name == "End of file")  
            break; 
        getline(my_file, inp_password);
          
        list_admin.push_back(new Player(inp_name, inp_password, -1)); // tat ca admin co ID bang -1
    }
    while(1);
    my_file.close();
}

void Storage::read_user_info_from_txt(string file) {
    list_user.resize(0);
    ifstream my_file(file);
    string inp_name;
    string inp_password;
    int inp_ID;
    do {
        getline(my_file, inp_name); 
        if (inp_name == "End of file")  
            break;  
        getline(my_file, inp_password);
        
        my_file >> inp_ID;
        my_file.ignore();
           
        list_user.push_back(new Player(inp_name, inp_password, inp_ID)); // tat ca admin co ID bang -1
    }
    while(1);
    my_file.close();
}

void Storage::save_admin_info_to_txt(string file) {
    ofstream my_file(file);
    for (int i = 0; i < list_admin.size(); i++) {
        my_file << list_admin[i]->get_name() << endl;
        my_file << list_admin[i]->get_password() << endl;
    }
    my_file << "End of file";
    my_file.close();
}

void Storage::save_user_info_to_txt(string file) {
    ofstream my_file(file);
    for (int i = 0; i < list_user.size(); i++) {
        my_file << list_user[i]->get_name() << endl;
        my_file << list_user[i]->get_password() << endl;
        my_file << list_user[i]->get_ID() << endl;
    }
    my_file << "End of file";
    my_file.close();

}




int Storage::last_ID() {
    return list_user[list_user.size() - 1]->get_ID();
}


void Storage::clear_game() {
    list_game.resize(0);
}












