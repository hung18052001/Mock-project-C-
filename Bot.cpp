#include "Bot.h"  

Person *Bot::clone() {
    return new Bot(*this);
}
string Bot::get_name() {}
void print_info() {}