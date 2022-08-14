#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>

using namespace std;

void bot_play_stone(vector<vector<string>> &board)
{
    string *str[100];
    int Count = 0;
    for (int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] != "O" && board[i][j] != "o"){
                str[Count] = &board[i][j];
                Count++;
            }
        }
    }
    srand(time(NULL));
    int temp = rand() % (Count - 0 + 1) + 0;
    *str[temp] = "O";
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
