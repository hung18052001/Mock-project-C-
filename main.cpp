#include <iostream>
#include "Game.cpp"
#include "Player.cpp"
#include "Person.cpp"

using namespace std;

int main() {
    Person *c1 = new Player("Dimash", "001000", 69);
    Person *c2 = new Player("Zhou Shen", "111111", 90);
    Game game(5, c1, c2);
    while (1) {
        int x, y; 
        cout << "Moi nguoi choi nhap toa do nuoc di: ";
        cin >> x >> y;
        game.add_stone(x, y);
        game.render();
        if (game.check_win() != -1) {
            game.set_winner();   
            break;
        }

    }
    
}


