#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void bot_play_stone(vector<vector<string>> &board)
{
    string temp = "";
    int Count = 0;
    do{
        int i = rand()% board.size();
        int j = rand()% board.size();
        temp = board[i][j];
        if( temp == "O" || temp == "o" ) {}
        else{
            board[i][j] = "O";
            Count++;
        }
    }while(Count != 1);
}

int main()
{
    vector<vector<string>> board{
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "},
        {" ", " ", " ", " ", " "}
    };
    board[1][1] = "O";
    board[2][2] = "O";
    bot_play_stone(board);
    bot_play_stone(board);
    bot_play_stone(board);
    bot_play_stone(board);
    for (int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j] << "    ";
        }
        cout << endl << endl;
    }

    return 0;
}
