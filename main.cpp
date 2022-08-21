#include <iostream>
<<<<<<< HEAD
#include "Game.cpp"
#include "GamePvP.cpp"
=======
#include "Bot.cpp"
#include "Game.cpp"
#include "GamePvP.cpp"
#include "GamePvE.cpp"
>>>>>>> sonth
#include "Player.cpp"
#include "Person.cpp"
#include "Storage.cpp"
#include "Manage.cpp"
#include "Guild.cpp"

<<<<<<< HEAD
=======

>>>>>>> sonth
using namespace std;
int main() {    
    Manage manage;
    Storage storage;
    Guild guild;
    storage.read_admin_info_from_txt("admin.txt");
    storage.read_user_info_from_txt("user.txt"); 
    while (1) {
        cout << "Chào mừng bạn đến với cờ caro.\n";
        cout << "Bây giờ bạn có các lựa chọn sau:\n";
        cout << "Nhập 1 để chuyển về quyền truy cập admin.\n";
        cout << "Nhập 2 để chuyển về quyền truy cập user.\n";
        cout << "Nhập 3 để xem hướng dẫn.\n";
        cout << "Nhập 4 để thoát game.\n";
        cout << "Mời bạn nhập lựa chọn: ";  
        int select;
        cin >> select;
        if (select == 1) {
            manage.admin_manage(storage);
            continue;
        }
    
        if (select == 2) {
            manage.user_manage(storage);
            continue;
        }
        if (select == 3) {
            guild.print_guild();
            continue;   
        }
        if (select == 4) {
            cout << "Thực hiên thoát chương trình.\n";
            storage.save_user_info_to_txt("user.txt");
            storage.save_admin_info_to_txt("admin.txt");   

<<<<<<< HEAD
int main() {
    Manage manage;
    Storage storage;
    Guild guild;
    storage.read_admin_info_from_txt("admin.txt");
    storage.read_user_info_from_txt("user.txt"); 
    while (1) {
        cout << "Chào mừng bạn đến với cờ caro.\n";
        cout << "Bây giờ bạn có các lựa chọn sau:\n";
        cout << "Nhập 1 để chuyển về quyền truy cập admin.\n";
        cout << "Nhập 2 để chuyển về quyền truy cập user.\n";
        cout << "Nhập 3 để xem hướng dẫn.\n";
        cout << "Nhập 4 để thoát game.\n";
        cout << "Mời bạn nhập lựa chọn: ";  
        int select;
        cin >> select;
        if (select == 1) {
            manage.admin_manage(storage);
            continue;
        }
    
        if (select == 2) {
            manage.user_manage(storage);
            continue;
        }
        if (select == 3) {
            guild.print_guild();
            continue;   
        }
        if (select == 4) {
            cout << "Thực hiên thoát chương trình.\n";
            storage.save_user_info_to_txt("user.txt");
            storage.save_admin_info_to_txt("admin.txt");   

            break;
        }

        continue;
    }


    
    
=======
            break;
        }
        continue;
    }
    return 0;
>>>>>>> sonth
}


