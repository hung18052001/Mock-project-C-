#include "Manage.h"

void Manage::sign_up(Storage &storage) {
    // for user 
    cout << "Bạn đang thực hiện đăng ký.\n";
    string inp_name;   
    string inp_password;
    cout << "Mời nhập tên người dùng: ";
    fflush(stdin);   
    getline(cin, inp_name);  
    cout << "Mời nhập mật khẩu: ";    
    getline(cin, inp_password); 
    int inp_ID = storage.last_ID();  
    storage.add_user(new Player(inp_name, inp_password, inp_ID));
    cout << "Đăng ký thành công.\n";


}

void Manage::user_manage(Storage &storage) {
    while(1) {
        cout << "Bạn đang ở quyền truy cập user.\n";
        cout << "Bạn có thể lựa chọn các tính năng sau:\n";
        cout << "Nhập 1 để tiến hành đăng ký.\n";
        cout << "Nhập 2 để tiến hành đăng nhập và chơi game PvP.\n";
        cout << "Nhâp 3 để tiến hành đăng nhập và chơi game PvE.\n";
        cout << "Nhập 4 để xem thông tin các game đã chơi.\n";
        cout << "Nhập 5 để quay lại trang chính.\n";
        cout << "Xin mời nhập lựa chọn: ";
        int select = 0;  
        cin >> select;
        if (select == 1) {
            sign_up(storage);
            continue;
        }
        if (select == 2) {
            Game *game_pvp = new GamePvP();
            sign_in_PvP(storage, game_pvp);    
            cout << "Mời nhập kích cỡ ô cờ: ";
            int inp_size = 0;
            cin >> inp_size;  
            game_pvp->set_size(inp_size);  
            
            game_pvp->play();  
            storage.add_game(game_pvp);
            continue;
        }
        if (select == 3) {
            Game *game_pve = new GamePvE();
            sign_in_PvE(storage, game_pve);    
            cout << "Mời nhập kích cỡ ô cờ: ";
            int inp_size = 0;
            cin >> inp_size;  
            game_pve->set_size(inp_size);  
            
            game_pve->play();
            storage.add_game(game_pve);
            continue;
        }
        if (select == 4) {
            cout << "Thông tin về các game đã chơi:\n";
            storage.print_game_info();
            continue;
        }
        if (select == 5) {
            cout << "Quay lại trang chính.\n";
            break;
        }



    }
}

void Manage::admin_manage(Storage &storage) {
    if (!sign_in_admin(storage)) return;
    while(1) {
        cout << "Bạn đang ở quyền truy cập admin.\n";
        cout << "Bạn có thể lựa chọn các tính năng sau:\n";
        cout << "Nhập 1 để xem thông tin các admin.\n";
        cout << "Nhập 2 để thêm một admin mới vào bộ nhớ.\n";
        cout << "Nhập 3 để tiến hành xóa admin theo tên tìm kiếm.\n";
        cout << "Nhập 4 để xem thông tin các user.\n";
        cout << "Nhập 5 để tiến hành thêm 1 user vào bộ nhớ.\n";
        cout << "Nhập 6 để xóa 1 user theo tên tìm kiếm.\n";
        cout << "Nhập 7 để xem lịch sử các game đã chơi.\n";
        cout << "Nhập 8 để xóa toàn bộ lịch sử game.\n";
        cout << "Nhập 9 quay lại trang chính.\n";
        // khi chương trình kết thúc thì thông tin của game cần được lưu lại vào file txt
        int select;
        cout << "Mời bạn nhập lựa chọn: ";
        cin >> select;
        if (select == 1) {
            cout << "Thông tin các admin.\n";
            storage.print_admin_info();
            continue;
        }
        if (select == 2) {
            string inp_name, inp_password;
            cout << "Mời nhập tên đăng ký: ";
            fflush(stdin);    
            getline(cin, inp_name);    
            cout << "Mời nhập mật khẩu: ";     
            getline(cin, inp_password);
            storage.add_admin(new Player(inp_name, inp_password, -1));
            cout << "Đã thêm admin mới.\n";
            continue;
        }
        if (select == 3) {
            string inp_name;    
            cout << "Nhập tên admin mà bạn muốn xóa: ";
            fflush(stdin);   
            getline(cin, inp_name);    
            storage.remove_admin(inp_name);
            continue;
        }

        if (select == 4) {
            cout << "Thông tin các user.\n";
            storage.print_user_info();
            continue;
        }
        if (select == 5) {
            string inp_name, inp_password;
            cout << "Mời nhập tên đăng ký: ";
            fflush(stdin);    
            getline(cin, inp_name);    
            cout << "Mời nhập mật khẩu: ";     
            getline(cin, inp_password);
            storage.add_user(new Player(inp_name, inp_password, storage.last_ID() + 1));
            cout << "Đã thêm user mới.\n";
            continue;
        }

        if (select == 6) {
            string inp_name;    
            cout << "Nhập tên user mà bạn muốn xóa: ";
            fflush(stdin);   
            getline(cin, inp_name);    
            storage.remove_user(inp_name);
            continue;
        }

        if (select == 7) {
            cout << "Lịch sử các game đã chơi.\n";
            storage.print_game_info();
            continue;
        }
        if (select == 8) {
            cout << "Đã xóa lịch sử chơi game.\n";
            storage.clear_game();
            continue;
        }
        if (select == 9) {
            cout << "Quay lại trang chính.\n";
            break; 
        }  
        cout << "Không tìm thấy lựa chọn phù hợp.\n";
        continue;
    }
}

void Manage::sign_in_PvP(Storage &storage, Game *&game) {
    for (int i = 1; i <= 2; i++) {
        while (1) {
            cout << "Mời người chơi thứ " << i << " đăng nhập.\n";
            string inp_name;
            string inp_password;
            cout << "Mời nhập tên: ";
            fflush(stdin);  
            getline(cin, inp_name);   
            cout << "Mời nhập pasword: ";
            getline(cin, inp_password);
            Person *p = storage.exist(inp_name, inp_password, false);
            if (p != NULL) {
                cout << "Người chơi thứ " << i << " đăng nhập thành công.\n";
                if (i == 1) game->set_character1(p);
                else game->set_character2(p);
                break;
            }
            cout << "Tên đăng nhập hoặc mật khẩu không hợp lệ.\n";
            continue;
        }
    } 
}



void Manage::sign_in_PvE(Storage &storage, Game *&game) {
   
        while (1) {
            cout << "Mời người chơi đăng nhập.\n";
            string inp_name;
            string inp_password;
            cout << "Mời nhập tên: ";
            fflush(stdin);  
            getline(cin, inp_name);   
            cout << "Mời nhập pasword: ";
            getline(cin, inp_password);
            Person *p = storage.exist(inp_name, inp_password, false);
            Person *bot = new Bot();
            if (p != NULL) {
                cout << "Người chơi đăng nhập thành công.\n";
                game->set_character1(p);
                game->set_character2(bot);
                break;
                
            }
            
            cout << "Tên đăng nhập hoặc mật khẩu không hợp lệ.\n";
            continue;
        }
    
}

bool Manage::sign_in_admin(Storage &storage) {
    
        cout << "Mời bạn đăng nhập để truy cập quyền admin.\n";
        string inp_name, inp_password;
        cout << "Mời nhập tên: ";     
        fflush(stdin);
        getline(cin, inp_name);   
        cout << "Mời nhập mật khẩu: ";
        getline(cin, inp_password);
        if (storage.exist(inp_name, inp_password, true)) {
            cout << "Đăng nhập thành công.\n";
            return true;
        }
        cout << "Tên đăng nhập hoặc mật khẩu không hợp lệ.\n";
        return false;    
}