#include "GameBot.h"
#include "Cell.h"

int GameBot::getSize() { return size; }
int GameBot::getLeft() { return current_x; }
int GameBot::getTop() { return current_y; }

int GameBot::getXAt(int i, int j) {
	return board[i][j].getX();
}

int GameBot::getYAt(int i, int j) {
	return board[i][j].getY();
}

void GameBot::addStone(int x, int y) {
	static int turnCount = 1;
	current_x = x;
	current_y = y;
	if (turnCount % 2 == 1) {
		player.set_pos_x(x);
		player.set_pos_y(y);
		board[x][y].setCheck(-1);
	}
	else {
		bot.set_pos_x(x);
		bot.set_pos_y(y);
		board[x][y].setCheck(1);
	}
	turnCount++;
}

GameBot::GameBot() {

}

GameBot::GameBot(int pSize, Player p, Bot b) {
	size = pSize;
	board.resize(pSize);    
    for (int i = 0; i < pSize; i++)  
        board[i].resize(pSize);  
	player = p;
	bot = b;
}

GameBot::~GameBot() {

}

int GameBot::SoDiemTanCong_DuyetNgang(int row, int col, const int Defend_Score[], const int Attack_Score[]) {
	int DiemDuyetNgang = 0;
	int ScoreAttack = 0;
	int soQuanTa = 0;
	int soQuanDich = 0;
	int soQuanTa2 = 0;
	int soQuanDich2 = 0;
	for (int Count = 1; Count < 6 && col + Count < size; Count++)
	{
		if (board[row][col + Count].getCheck() == 1)
			soQuanTa++;
		if (board[row][col + Count].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row][col + Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col + Count2 < size; Count2++)
			{
				if (board[row][col + Count2].getCheck() == 1)
					soQuanTa2++;
				if (board[row][col + Count2].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row][col + Count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int Count = 1; Count < 6 && col - Count >= 0; Count++)
	{
		if (board[row] [col - Count].getCheck() == 1)
			soQuanTa++;
		if (board[row][col - Count].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row][col - Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col - Count2 >= 0; Count2++)
			{
				if (board[row][col - Count2].getCheck() == 1)
					soQuanTa2++;
				if (board[row][col - Count2].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row][col - Count2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	// soQuanDich = 2 nghĩa là đã bị chặn hai đầu
	if (soQuanDich == 2)
		return 0;
    // Hai bên chỉ có quân ta hoặc chỉ có ô trống
	if (soQuanDich == 0)
		DiemDuyetNgang += Attack_Score[soQuanTa] * 2;
	else
		DiemDuyetNgang += Attack_Score[soQuanTa]; // 1 bên có quân địch
    // trường hợp này dùng để xét khi mà sau khi gặp ô trống rồi lại gặp quân địch bởi khi gặp quân địch lần đầu thì break; luôn rồi
	if (soQuanDich2 == 0)
		DiemDuyetNgang += Attack_Score[soQuanTa2] * 2;
	else
		DiemDuyetNgang += Attack_Score[soQuanTa2];
    // trường hợp này giống kiểu x x " " x thì đánh x vào ô " " sẽ tốt hơn
	if (soQuanTa >= soQuanTa2)
		DiemDuyetNgang -= 1;
	else
		DiemDuyetNgang -= 2;
    // soQuanta = 4 điểm được x2 để tối ưu hóa mức ưu tiên
	if (soQuanTa == 4)
		DiemDuyetNgang *= 2;
    // soQuanTa = 0 thì xét đến trường hợp phòng thủ
	if (soQuanTa == 0)
		DiemDuyetNgang += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetNgang += Defend_Score[soQuanDich];
	if (soQuanTa2 == 0)
		DiemDuyetNgang += Defend_Score[soQuanDich2] * 2;
	else
		DiemDuyetNgang += Defend_Score[soQuanDich2];
	return DiemDuyetNgang;
}

int GameBot::SoDiemTanCong_DuyetDoc(int row, int col, const int Defend_Score[], const int Attack_Score[]) {
	int DiemDuyetDoc = 0;
	int ScoreAttack = 0;
	int soQuanTa = 0;
	int soQuanDich = 0;
	int soQuanTa2 = 0;
	int soQuanDich2 = 0;
	for (int Count = 1; Count < 6 && row + Count < size; Count++)
	{
		if (board[row + Count][col].getCheck() == 1)
			soQuanTa++;
		if (board[row + Count][col].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row + Count][col].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && row + Count2 < size; Count2++)
			{
				if (board[row + Count2][col].getCheck() == 1)
					soQuanTa2++;
				if (board[row + Count2][col].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row + Count2][col].getCheck() == 0)
					break;
			}
			break;
		}

	}

	for (int Count = 1; Count < 6 && row - Count >= 0; Count++)
	{
		if (board[row - Count] [col].getCheck() == 1)
			soQuanTa++;
		if (board[row - Count][ col].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row - Count][col].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && row - Count2 >= 0; Count2++)
			{
				if (board[row - Count2][col].getCheck() == 1)
					soQuanTa2++;
				if (board[row - Count2][col].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row - Count2][col].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}

	if (soQuanDich == 2)
		return 0;
	if (soQuanDich == 0)
		DiemDuyetDoc += Attack_Score[soQuanTa] * 2;
	else
		DiemDuyetDoc += Attack_Score[soQuanTa];
	if (soQuanDich2 == 0)
		DiemDuyetDoc += Attack_Score[soQuanTa2] * 2;
	else
		DiemDuyetDoc += Attack_Score[soQuanTa2];

	if (soQuanTa >= soQuanTa2)
		DiemDuyetDoc -= 1;
	else
		DiemDuyetDoc -= 2;
	if (soQuanTa == 4)
		DiemDuyetDoc *= 2;
	if (soQuanTa == 0)
		DiemDuyetDoc += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetDoc += Defend_Score[soQuanDich];
	if (soQuanTa2 == 0)
		DiemDuyetDoc += Defend_Score[soQuanDich2] * 2;
	else
		DiemDuyetDoc += Defend_Score[soQuanDich2];
	return DiemDuyetDoc;
}

int GameBot::SoDiemTanCong_DuyetCheo1(int row, int col, const int Defend_Score[], const int Attack_Score[])
{
	int DiemDuyetCheo1 = 0;
	int ScoreAttack = 0;
	int soQuanTa = 0;
	int soQuanDich = 0;
	int soQuanTa2 = 0;
	int soQuanDich2 = 0;
	for (int Count = 1; Count < 6 && col + Count < size && row + Count < size; Count++)
	{
		if (board[row + Count][ col + Count].getCheck() == 1)
			soQuanTa++;
		if (board[row + Count][col + Count].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row + Count][col + Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col + Count2 < size && row + Count2 < size; Count2++)
			{
				if (board[row + Count2][col + Count2].getCheck() == 1)
					soQuanTa2++;
				if (board[row + Count2][col + Count2].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row + Count2][col + Count2].getCheck() == 0)
				{
					break;
				}
			}
			break;
		}
	}

	for (int Count = 1; Count < 6 && col - Count >= 0 && row - Count >= 0; Count++)
	{
		if (board[row - Count] [col - Count].getCheck() == 1)
			soQuanTa++;
		if (board[row - Count][col - Count].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row - Count][col - Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col - Count2 >= 0 && row - Count2 >= 0; Count2++)
			{
				if (board[row - Count2][col - Count2].getCheck() == 1)
					soQuanTa2++;
				if (board[row - Count2][col - Count2].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row - Count2][col - Count2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (soQuanDich == 2)
		return 0;
	if (soQuanDich == 0)
		DiemDuyetCheo1 += Attack_Score[soQuanTa] * 2;
	else
		DiemDuyetCheo1 += Attack_Score[soQuanTa];
	if (soQuanDich2 == 0)
		DiemDuyetCheo1 += Attack_Score[soQuanTa2] * 2;
	else
		DiemDuyetCheo1 += Attack_Score[soQuanTa2];

	if (soQuanTa >= soQuanTa2)
		DiemDuyetCheo1 -= 1;
	else
		DiemDuyetCheo1 -= 2;
	if (soQuanTa == 4)
		DiemDuyetCheo1 *= 2;
	if (soQuanTa == 0)
		DiemDuyetCheo1 += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetCheo1 += Defend_Score[soQuanDich];
	if (soQuanTa2 == 0)
		DiemDuyetCheo1 += Defend_Score[soQuanDich2] * 2;
	else
		DiemDuyetCheo1 += Defend_Score[soQuanDich2];
	return DiemDuyetCheo1;
}

int GameBot::SoDiemTanCong_DuyetCheo2(int row, int col, const int Defend_Score[], const int Attack_Score[]) {
	int DiemDuyetCheo2 = 0;
	int ScoreAttack = 0;
	int soQuanTa = 0;
	int soQuanDich = 0;
	int soQuanTa2 = 0;
	int soQuanDich2 = 0;
	for (int Count = 1; Count < 6 && col - Count >= 0 && row + Count < size; Count++)
	{
		if (board[row + Count] [col - Count].getCheck() == 1)
			soQuanTa++;
		if (board[row + Count][col - Count].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row + Count][col - Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col - Count2 >= 0 && row + Count2 < size; Count2++)
			{
				if (board[row + Count2][col - Count2].getCheck() == 1)
					soQuanTa2++;
				if (board[row + Count2][col - Count2].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row + Count2][col - Count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int Count = 1; Count < 6 && col + Count < size && row - Count >= 0; Count++)
	{
		if (board[row - Count] [col + Count].getCheck() == 1)
			soQuanTa++;
		if (board[row - Count][col + Count].getCheck() == -1)
		{
			soQuanDich++;
			break;
		}
		if (board[row - Count][col + Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col + Count2 < size && row - Count2 >= 0; Count2++)
			{
				if (board[row - Count2][col + Count2].getCheck() == 1)
					soQuanTa2++;
				if (board[row - Count2][col + Count2].getCheck() == -1)
				{
					soQuanDich2++;
					break;
				}
				if (board[row - Count2][col + Count2].getCheck() == 0)
					break;
			}
			break;
		}
	}
	if (soQuanDich == 2)
		return 0;
	if (soQuanDich == 0)
		DiemDuyetCheo2 += Attack_Score[soQuanTa] * 2;
	else
		DiemDuyetCheo2 += Attack_Score[soQuanTa];
	if (soQuanDich2 == 0)
		DiemDuyetCheo2 += Attack_Score[soQuanTa2] * 2;
	else
		DiemDuyetCheo2 += Attack_Score[soQuanTa2];

	if (soQuanTa >= soQuanTa2)
		DiemDuyetCheo2 -= 1;
	else
		DiemDuyetCheo2 -= 2;
	if (soQuanTa == 4)
		DiemDuyetCheo2 *= 2;
	if (soQuanTa == 0)
		DiemDuyetCheo2 += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetCheo2 += Defend_Score[soQuanDich];
	if (soQuanTa2 == 0)
		DiemDuyetCheo2 += Defend_Score[soQuanDich2] * 2;
	else
		DiemDuyetCheo2 += Defend_Score[soQuanDich2];
	return DiemDuyetCheo2;
}

int GameBot::SoDiemPhongThu_DuyetDoc(int row, int col, const int Defend_Score[], const int Attack_Score[]) {
	int DiemDuyetDoc = 0;
	int ScoreDefend = 0;
	int soQuanDich = 0;
	int soQuanTa = 0;
	int soQuanDich2 = 0;
	int soQuanTa2 = 0;
	for (int Count = 1; Count < 6 && row + Count < size; Count++)
	{
		if (board[row + Count][ col].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}
		if (board[row + Count][col].getCheck() == -1)
			soQuanDich++;
		if (board[row + Count][col].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && row + Count2 < size; Count2++)
			{
				if (board[row + Count2][col].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}
				if (board[row + Count2][col].getCheck() == -1)
					soQuanDich2++;
				if (board[row + Count2][col].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int Count = 1; Count < 6 && row - Count >= 0; Count++)
	{
		if (board[row - Count][col].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}
		if (board[row - Count][col].getCheck() == -1)
			soQuanDich++;
		if (board[row - Count][col].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && row - Count2 >= 0; Count2++)
			{
				if (board[row - Count2][col].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}
				if (board[row - Count2][col].getCheck() == -1)
					soQuanDich2++;
				if (board[row - Count2][col].getCheck() == 0)
					break;
			}
			break;
		}
	}


	if (soQuanTa == 2)
		return 0;
	if (soQuanTa == 0)
		DiemDuyetDoc += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetDoc += Defend_Score[soQuanDich];
	/*
	if (soQuanTa == 0)
	DiemDuyetDoc += Defend_Score[soQuanDich2] * 2;
	else
	DiemDuyetDoc += Defend_Score[soQuanDich2];
	*/
	if (soQuanDich >= soQuanDich2)
		DiemDuyetDoc -= 1;
	else
		DiemDuyetDoc -= 2;
	if (soQuanDich == 4)
		DiemDuyetDoc *= 2;
	return DiemDuyetDoc;
}

int GameBot::SoDiemPhongThu_DuyetNgang(int row, int col, const int Defend_Score[], const int Attack_Score[]) {
	int DiemDuyetNgang = 0;
	int ScoreDefend = 0;
	int soQuanDich = 0;
	int soQuanTa = 0;
	int soQuanDich2 = 0;
	int soQuanTa2 = 0;
	for (int Count = 1; Count < 6 && col + Count < size; Count++)
	{
		if (board[row][ col + Count].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}
		if (board[row][col + Count].getCheck() == -1)
			soQuanDich++;
		if (board[row][col + Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col + Count2 < size; Count2++)
			{
				if (board[row][col + Count2].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}
				if (board[row][col + Count2].getCheck() == -1)
					soQuanDich2++;
				if (board[row][col + Count2].getCheck() == 0)
					break;
			}
			break;
		}
	}

	for (int Count = 1; Count < 6 && col - Count >= 0; Count++)
	{
		if (board[row][ col - Count].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}
		if (board[row][col - Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col - Count2 >= 0; Count2++)
			{
				if (board[row][col - Count2].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}
				if (board[row][col - Count2].getCheck() == 0)
					break;
				if (board[row][col - Count2].getCheck() == -1)
					soQuanDich2++;
			}
			break;
		}
		if (board[row][col - Count].getCheck() == -1)
			soQuanDich++;
	}

	if (soQuanTa == 2)
		return 0;
	if (soQuanTa == 0)
		DiemDuyetNgang += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetNgang += Defend_Score[soQuanDich];
	/*
	if (soQuanTa == 0)
	DiemDuyetDoc += Defend_Score[soQuanDich2] * 2;
	else
	DiemDuyetDoc += Defend_Score[soQuanDich2];
	*/
	if (soQuanDich >= soQuanDich2)
		DiemDuyetNgang -= 1;
	else
		DiemDuyetNgang -= 2;
	if (soQuanDich == 4)
		DiemDuyetNgang *= 2;
	return DiemDuyetNgang;
}

int GameBot::SoDiemPhongThu_DuyetCheo1(int row, int col, const int Defend_Score[], const int Attack_Score[]) {
	int DiemDuyetCheo1 = 0;
	int ScoreDefend = 0;
	int soQuanDich = 0;
	int soQuanTa = 0;
	int soQuanDich2 = 0;
	int soQuanTa2 = 0;
	for (int Count = 1; Count < 6 && col + Count < size && row + Count < size; Count++)
	{
		if (board[row + Count][ col + Count].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}
		if (board[row + Count][col + Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col + Count2 < size && row + Count2< size; Count2++)
			{
				if (board[row + Count2][col + Count2].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}
				if (board[row + Count2][col + Count2].getCheck() == 0)
					break;
				if (board[row + Count2][col + Count2].getCheck() == -1)
					soQuanDich2++;
			}
			break;
		}
		if (board[row + Count][col + Count].getCheck() == -1)
			soQuanDich++;
	}

	for (int Count = 1; Count < 6 && col - Count >= 0 && row - Count >= 0; Count++)
	{
		if (board[row - Count] [col - Count].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}

		if (board[row - Count][col - Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col - Count2 >= 0 && row - Count2 >= 0; Count2++)
			{
				if (board[row - Count2][col - Count2].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}

				if (board[row - Count2][col - Count2].getCheck() == 0)
					break;
				if (board[row - Count2][col - Count2].getCheck() == -1)
					soQuanDich2++;
			}
			break;
		}
		if (board[row - Count][col - Count].getCheck() == -1)
			soQuanDich++;
	}
	if (soQuanTa == 2)
		return 0;
	if (soQuanTa == 0)
		DiemDuyetCheo1 += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetCheo1 += Defend_Score[soQuanDich];
	/*
	if (soQuanTa == 0)
	DiemDuyetDoc += Defend_Score[soQuanDich2] * 2;
	else
	DiemDuyetDoc += Defend_Score[soQuanDich2];
	*/
	if (soQuanDich >= soQuanDich2)
		DiemDuyetCheo1 -= 1;
	else
		DiemDuyetCheo1 -= 2;
	if (soQuanDich == 4)
		DiemDuyetCheo1 *= 2;
	return DiemDuyetCheo1;
}

int GameBot::SoDiemPhongThu_DuyetCheo2(int row, int col, const int Defend_Score[], const int Attack_Score[]) {
	int DiemDuyetCheo2 = 0;
	int ScoreDefend = 0;
	int soQuanDich = 0;
	int soQuanTa = 0;
	int soQuanDich2 = 0;
	int soQuanTa2 = 0;
	for (int Count = 1; Count < 6 && col - Count >= 0 && row + Count < size; Count++)
	{
		if (board[row + Count] [col - Count].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}
		if (board[row + Count][col - Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count2 < 7 && col - Count2 >= 0 && row + Count2 < size; Count2++)
			{
				if (board[row + Count2][col - Count2].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}
				if (board[row + Count2][col - Count2].getCheck() == 0)
					break;
				if (board[row + Count2][col - Count2].getCheck() == -1)
					soQuanDich2++;
			}
			break;
		}
		if (board[row + Count][col - Count].getCheck() == -1)
			soQuanDich++;
	}

	for (int Count = 1; Count < 6 && col + Count < size && row - Count >= 0; Count++)
	{
		if (board[row - Count][ col + Count].getCheck() == 1)
		{
			soQuanTa++;
			break;
		}
		if (board[row - Count][col + Count].getCheck() == 0)
		{
			for (int Count2 = 2; Count < 7 && col + Count2 < size && row - Count2 >= 0; Count2++)
			{
				if (board[row - Count2][col + Count2].getCheck() == 1)
				{
					soQuanTa2++;
					break;
				}
				if (board[row - Count2][col + Count2].getCheck() == 0)
					break;
				if (board[row - Count2][col + Count2].getCheck() == -1)
					soQuanDich2++;
			}
			break;
		}
		if (board[row - Count][col + Count].getCheck() == -1)
			soQuanDich++;
	}


	if (soQuanTa == 2)
		return 0;
	if (soQuanTa == 0)
		DiemDuyetCheo2 += Defend_Score[soQuanDich] * 2;
	else
		DiemDuyetCheo2 += Defend_Score[soQuanDich];

	if (soQuanDich >= soQuanDich2)
		DiemDuyetCheo2 -= 1;
	else
		DiemDuyetCheo2 -= 2;
	if (soQuanDich == 4)
		DiemDuyetCheo2 *= 2;
	return DiemDuyetCheo2;
}

_Point GameBot::Tim_Kiem_NuocDi_1() {
	_Point Pos ;
	int row=0, col=0;
	int Diem = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int DiemTanCong = 0;
			int DiemPhongThu = 0;
			if (board[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score1, Attack_Score1);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score1, Attack_Score1);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						row = i;
						col = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						row = i;
						col = j;
					}
				}
			}
		}
	}
	Pos.setX(col);
	Pos.setY(row);
	return Pos;
}

_Point GameBot::Tim_Kiem_NuocDi_2() {
	_Point Pos;
	int row = 0, col = 0;
	int Diem = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			int DiemTanCong = 0;
			int DiemPhongThu = 0;
			if (board[i][j].getCheck() == 0)
			{
				DiemTanCong += SoDiemTanCong_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemTanCong += SoDiemTanCong_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				DiemPhongThu += SoDiemPhongThu_DuyetDoc(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetNgang(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo1(i, j, Defend_Score2, Attack_Score2);
				DiemPhongThu += SoDiemPhongThu_DuyetCheo2(i, j, Defend_Score2, Attack_Score2);

				if (DiemTanCong > DiemPhongThu)
				{
					if (Diem < DiemTanCong)
					{
						Diem = DiemTanCong;
						row = i;
						col = j;
					}
				}
				else
				{
					if (Diem < DiemPhongThu)
					{
						Diem = DiemPhongThu;
						row = i;
						col = j;
					}
				}
			}
		}
	}
	Pos.setX(col);
	Pos.setY(row);
	return Pos;
}