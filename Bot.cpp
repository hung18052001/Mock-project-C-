#include "Bot.h"  

Person *Bot::clone() {
    return new Bot(*this);
}