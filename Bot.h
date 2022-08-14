#ifndef p6
#define p6 
#include "Person.h"
class Bot: public Person{
    public:
        Person *clone();
        string get_name();
        void print_info();
};
#endif