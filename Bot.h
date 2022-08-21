#ifndef p6
#define p6 
#include "Person.h"
class Bot: public Person{
    private:
        string name;
    public:
        Bot();
        Bot(string name);
        Person *clone();
        string get_name();
        void print_info();
<<<<<<< HEAD
=======
        void set_name(string name);
>>>>>>> sonth
};
#endif