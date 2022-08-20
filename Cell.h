#ifndef p3
#define p3
#include <iostream>
using namespace std;


class Cell {
	private:
		string value; // o or x or " "
	public:
		Cell(): value(" ") {}
		string get_value() const{
			return value;
		}
		void set_value(string value) {
			this->value = value;
		}
};

#endif