#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
int board[19][19];
//우, 우하단, 하단, 우상단
int dy[4] = { 0, 1, 1, -1 };
int dx[4] = { 1, 1, 0, 1 };
bool checkWin(int y, int x, int dir, int color)
{	
	int by = y - dy[dir];
	int bx = x - dx[dir];
	if (by >= 0 && bx >= 0 && by < 19 && board[by][bx] == color)
		return false;

	int cnt = 1;
	while (true)
	{
		y += dy[dir];
		x += dx[dir];
		if (y >= 0 && x < 19 && y < 19 && board[y][x] == color)
		{
			cnt++;
			continue;
		}
		break;
	}
	if (cnt == 5)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			cin >> board[i][j];
		}
	}
	
	for (int i = 0; i < 19; ++i)
	{
		for (int j = 0; j < 19; ++j)
		{
			//black
			if (board[i][j] == 1)
			{
				for (int k = 0; k < 4; ++k)
				{
					bool result = checkWin(i, j, k, 1);
					if (result)
					{
						cout << "1\n" << i + 1 << " " << j + 1;
						return 0;
					}
				}
			}
			else if(board[i][j] == 2)
			{
				for (int k = 0; k < 4; ++k)
				{
					bool result = checkWin(i, j, k, 2);
					if (result)
					{
						cout << "2\n" << i + 1 << " " << j + 1;
						return 0;
					}
				}
			}
		}
	}
	cout << "0";
	return 0;
}