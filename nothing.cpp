#include <iostream>
#include <vector>
using namespace std;
int main() {
    int x = 3;
    int *p = &x;  //
    vector<int> u;
    u.push_back(*p);
    cout << u[0];
}