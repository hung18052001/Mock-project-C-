#include "_Point.h"

const int Defend_Score1[7] = { 0, 10, 100, 1000, 10000, 100000 };
const int Attack_Score1[7] = { 0, 80, 800, 8000, 80000, 800000 };
// 2 mảng điểm tấn công phòng thủ cho máy khó, điểm atk cao hơn để ván game kêt thúc nhanh tránh hòa
const int Defend_Score2[7] = { 1, 2, 3, 1, 1, 1 }; // đoạn sau 1 điểm vì nó là mức dễ
const int Attack_Score2[7] = { 2, 3, 4, 5, 6, 7}; // đánh xa thì điểm cao
// 2 mảng điểm tấn công phòng thủ cho máy dễ

class _Board{
    int _size; // kích thước bàn cờ
    int _left; // tọa độ từ trái sang 1 2 3 ...
    int _top; // tọa độ từ trên xuống 1 2 3 ...
    _Point **board;
public:
    int getSize();
	// Lấy giá trị _size
	int getLeft();
	// Lấy giá trị _left
	int getTop();
	// Lấy giá trị _top
	int getXAt(int, int);
	int getYAt(int, int);
	// Lấy tọa độ x,y tại vị trí i,j trên bàn cờ mảng 2 chiều board
	int get_Check(int i, int j){ return board[i][j].getCheck(); }
	// Lấy giá trị _check trên mảng 2 chiều . nhận biết X O và ô trống.

    _Point Tim_Kiem_NuocDi_1(); // Tìm nước đi cho máy khó
	_Point Tim_Kiem_NuocDi_2(); // Tìm nước đi cho máy dễ
	int SoDiemTanCong_DuyetDoc(int, int, const int Defend_Score[], const int Attack_Score[]);
	int SoDiemTanCong_DuyetNgang(int, int, const int Defend_Score[], const int Attack_Score[]);
	int SoDiemTanCong_DuyetCheo1(int, int, const int Defend_Score[], const int Attack_Score[]);
	int SoDiemTanCong_DuyetCheo2(int, int, const int Defend_Score[], const int Attack_Score[]);
	int SoDiemPhongThu_DuyetDoc(int, int, const int Defend_Score[], const int Attack_Score[]);
	int SoDiemPhongThu_DuyetNgang(int, int, const int Defend_Score[], const int Attack_Score[]);
	int SoDiemPhongThu_DuyetCheo1(int, int, const int Defend_Score[], const int Attack_Score[]);
	int SoDiemPhongThu_DuyetCheo2(int, int, const int Defend_Score[], const int Attack_Score[]);
	// Duyệt Các Ô Trống tính điểm cho từng ô theo dọc , ngang , chéo ngược , chéo xuôi.

	_Board();
	_Board(int pSize,int pX,int pY);
	~_Board();
};
