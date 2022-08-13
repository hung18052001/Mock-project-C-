#include "Person.h"
Person::Person(): pos_x(-1), pos_y(-1) {}

Person::Person(int x, int y): pos_x(x), pos_y(y) {}

int Person::get_pos_x() {
    return pos_x;
}

int Person::get_pos_y() {
    return pos_y;
}

void Person::set_pos_x(int x) {
    pos_x = x;
}

void Person::set_pos_y(int y) {
    pos_y = y;
}


