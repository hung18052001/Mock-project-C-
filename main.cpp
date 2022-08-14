#include <iostream>
#include "Game.h"
using namespace std;

int main() {
    Game newgame(10);
    newgame.render();
    cout << '\n';

    do {
        cout << "Input: " << '\n';
        int xTemp{}, yTemp{};
        cin >> xTemp >> yTemp;
        newgame.update(xTemp, yTemp);
        newgame.render();
        cout << '\n';
    } while (true);

    return 0;
}


