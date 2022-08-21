#include "Bot.h"  

Bot::Bot(): 
    Person(), name("") {}
Bot::Bot(string name): 
    Person(), name(name) {

}
Person *Bot::clone() {
    return new Bot(*this);
}
<<<<<<< HEAD
string Bot::get_name() {}
void print_info() {}
=======
string Bot::get_name() {
    return name;
}
void Bot::print_info() {}
void Bot::set_name(string name) {
    this->name = name;
}
>>>>>>> sonth
