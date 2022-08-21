#include "Guild.h"

void Guild::print_guild(){
	cout << "\t---------------------------------------------------Caro Game------------------------------------------------" << endl;
	cout << "\t 1. Đăng nhập admin để thực hiện các quyền hạn như:" << endl;
	cout << "\t\t + xem thông tin người chơi." << endl;
	cout << "\t\t + thêm 1 admin mới." << endl;
	cout << "\t\t + xóa admin theo tên tìm kiếm." << endl;
	cout << "\t\t + thêm người chơi." << endl;
	cout << "\t\t + xem lịch sử games đã chơi." << endl;
	cout << "\t\t + xóa lịch sử games." << endl;
	cout << "\t    (lưu ý: chỉ áp dụng đối với các tài khoản admin) " << endl;
	cout << "\t 2. Đăng nhập user để tham gia chơi. " << endl;
	cout << "\t    Đối với tài khoản chưa đăng ý -> chọn sign up để tạo tài khoản.                                        " << endl;
	cout << "\t 3. Luật chơi: có hai chế độ chính <Đánh Bot> và <Chơi 2 người>" << endl;
	cout << "\t\t + <Đánh Bot> : Người chơi sẽ đánh với máy ảo, thực hiện nhập vị trí theo ô bàn cờ để đánh dấu nước đi," << endl;
	cout << "\t\t                bên nào tạo được đường (ngang, dọc, chéo) 4 ô liên tiếp không bị chặn 1 đầu" << endl;
	cout << "\t\t                và đường 5 ô liên tiếp không bị chặn 2 đầu sẽ dành chiến thắng." << endl;
	cout << "\t\t + <Chơi 2 người> : 2 player sẽ chơi với nhau, cách thức và luật chơi tương tự với chế độ <Đánh Bot>." << endl;
	cout << "\t 4. Thoát Game. " << endl;
	cout << "\t------------------------------------------------------------------------------------------------------------" << endl;
}