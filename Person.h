#ifndef p1
#define p1
#include <iostream>
using namespace std;


using namespace std;
class Person {
    private:
        // neu nhan vat A dang trong mot tran co caro thi day la toa do cua nuoc di nhan vat A vua danh
        // luu y nguoi choi A o day co the la nguoi hoac may
        // neu ho khong o trong tran dau, mac dinh pos_x, pos_y = -1
        int pos_x; 
        int pos_y;
    public: 
        Person();
        Person(int x, int y);
        int get_pos_x();
        int get_pos_y();
        void set_pos_x(int x);  
        void set_pos_y(int y);  
        virtual Person *clone() = 0;   

};
#endif