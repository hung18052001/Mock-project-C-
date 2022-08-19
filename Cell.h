#ifndef p3
#define p3
#include <iostream>
using namespace std;


class Cell {
	private:
		string value; // o or x or " "
	public:
		string get_value() {
			return value;
		}
		void set_value(string value) {
			this->value = value;
		}
};

class _Point{
    int _x;
    int _y;
    // Tọa độ x y trên bàn cờ
	int _check;
	// Biến nhận biết X và O ( -1 = X , 1 = O, 0 = Ô trống )
public:
	int getX() {
		return _x;
	}

	int getY() {
		return _y;
	}

	int getCheck() {
		return _check;
	}

	void setX(int pX) {
		_x = pX;
	}

	void setY(int pY) {
		_y = pY;
	}

	void setCheck(int value) {
		_check = value;
	}

	_Point() {
		_x = 0;
		_y = 0;
		_check = 0;
	}

	_Point(int x, int y) {
		_x = x;
		_y = y;
		_check = 0;
	}

	_Point operator=(const _Point& p) {
		_x = p._x;
		_y = p._y;
		_check = p._check;
		return *this;
	}

	~_Point() {}
};

#endif
