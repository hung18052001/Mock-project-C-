#include "Player.h"

Player::Player(): 
    Person(),  name(""), password(""), ID(0) {}

Player::Player(int x, int y, string name, string password, int ID): 
    Person(x, y), name(name), password(password), ID(ID) {}   

string Player::get_name() {
    return name;
}

string Player::get_password() {
    return password;
}

int Player::get_ID() {
    return ID;
}

void Player::set_name(string name) {
    this->name = name;
}

void Player::set_password(string password) {
    this->password = password;
}

void Player::set_ID(int ID) {
    this->ID = ID;
}

Person *Player::clone() {
    return new Player(*this);
}


