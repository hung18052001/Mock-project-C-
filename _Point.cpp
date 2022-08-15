#include "_Point.h"

int _Point::getX()
{
	return _x;
}
int _Point::getY()
{
	return _y;
}
int _Point::getCheck()
{
	return _check;
}
void _Point::setX(int pX)
{
	_x = pX;
}
void _Point::setY(int pY)
{
	_y = pY;
}
void _Point::setCheck(int value)
{
	_check = value;
}
_Point::_Point()
{
	_x = 0;
	_y = 0;
	_check = 0;
}
_Point::_Point(int x, int y)
{
	_x = x;
	_y = y;
	_check = 0;
}

_Point::~_Point()
{
}