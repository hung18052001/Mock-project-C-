#include "Player.h"

Player::Player(): 
    Person(),  name(""), password(""), ID(-1) {}

Player::Player(string name, string password, int ID): 
    Person(), name(name), password(password), ID(ID) {}   

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

void Player::print_info() {
    cout << "Ten: " << this->get_name() << endl;   
    cout << "Mat khau: " << this->get_password() << endl; 
    cout << "ID: " << this->get_ID() << endl;
}

Person *Player::clone() {
    return new Player(*this);
}





