#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

int R, C, K;	//행, 열, 온도
int arr[21][21];	//입력받을 배열
int currArr[21][21];	//현재온도 배열
int nextArr[21][21];	//계산할 배열
int wallNum;
int wall[21][21][21][21];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
int dirX[4][3] = { {1, 1, 1}, {-1, -1, -1}, {-1, 0, 1}, {-1, 0, 1} };
int dirY[4][3] = { {-1, 0, 1}, {-1, 0, 1}, {-1, -1, -1}, {1, 1, 1} };
typedef struct yx {
	int y;
	int x;
} yx;
vector<yx> machine;
vector<yx> needToCheck;

bool checkWall(int yy, int y, int xx, int x, int dir)
{
	if (yy == y || xx == x)
	{
		return !wall[yy][xx][y][x];
	}
	else
	{
		if (dir == 0 || dir == 1)
		{
			return wall[yy][x][y][x] == 0 && wall[yy][x][yy][xx] == 0;
		}
		else
		{
			return wall[y][xx][y][x] == 0 && wall[y][xx][yy][xx] == 0;
		}
	}
}

bool simulation()
{
	//init
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			nextArr[i][j] = 0;
		}
	}

	// 온풍기 작동 시 온도 변화 계산
	int weight;
	int my, mx, dir;
	int y, x, qSize, yy, xx;
	int checkVisited[21][21];
	for (int m = 0; m < machine.size(); ++m)
	{
		for (int i = 1; i <= 20; ++i)
		{
			for (int j = 1; j <= 20; ++j)
			{
				checkVisited[i][j] = 0;
			}
		}

		y = machine[m].y;
		x = machine[m].x;
		dir = arr[y][x] - 1;
		weight = 5;

		x += dx[dir];
		y += dy[dir];

		nextArr[y][x] += weight--;
		queue<yx> q;
		q.push({ y, x });
		while (!q.empty())
		{
			qSize = q.size();
			for (int qIndex = 0; qIndex < qSize; ++qIndex)
			{
				y = q.front().y;
				x = q.front().x;
				q.pop();

				for (int k = 0; k < 3; ++k)
				{
					yy = y + dirY[dir][k];
					xx = x + dirX[dir][k];
					if (xx <= C && xx > 0 && yy <= R && yy > 0 && checkVisited[yy][xx] == 0 && checkWall(yy, y, xx, x, dir))
					{
						q.push({ yy, xx });
						nextArr[yy][xx] += weight;
						checkVisited[yy][xx] = 1;
					}
				}
			}
			weight--;
			if (weight <= 0)
			{
				break;
			}
		}
	}
	
	// update
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			currArr[i][j] += nextArr[i][j];
			nextArr[i][j] = 0;
		}
	}

	//온도 조절 계산
	int diff;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				y = dy[k] + i;
				x = dx[k] + j;
				if (y > 0 && y <= R && x > 0 && x <= C && wall[y][x][i][j] == 0)
				{
					diff = currArr[i][j] - currArr[y][x];
					if (diff > 0)
					{
						nextArr[y][x] += diff / 4;
						nextArr[i][j] -= diff / 4;
					}
				}
			}
		}
	}

	//update
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			currArr[i][j] += nextArr[i][j];
			nextArr[i][j] = 0;
		}
	}

	//외곽 온도 -1
	for (int i = 1; i <= R; ++i)
	{
		if (currArr[i][1] > 0)
			currArr[i][1] --;
		if(currArr[i][C] > 0)
			currArr[i][C] --;
	}
	for (int i = 2; i <= C - 1; ++i)
	{
		if (currArr[1][i] > 0)
			currArr[1][i] --;
		if (currArr[R][i] > 0)
			currArr[R][i] --;
	}

	for (int i = 0; i < needToCheck.size(); ++i)
	{
		if (currArr[needToCheck[i].y][needToCheck[i].x] < K)
		{
			return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int in1, in2, in3;
	cin >> R >> C >> K;
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= C; ++j)
		{
			cin >> in1;
			arr[i][j] = in1;
			if (in1 == 5)
			{
				needToCheck.push_back({i, j});
			}
			else if (in1 > 0)
			{
				machine.push_back({i, j});
			}
		}
	}

	cin >> wallNum;
	for (int i = 0; i < wallNum; ++i)
	{
		cin >> in1 >> in2 >> in3;
		if (in3)
		{
			wall[in1][in2][in1][in2 + 1] = 1;
			wall[in1][in2 + 1][in1][in2] = 1;
		}
		else
		{
			wall[in1][in2][in1 - 1][in2] = 1;
			wall[in1 - 1][in2][in1][in2] = 1;
		}
	}

	// simulation
	int chocolate = 0;
	while (chocolate <= 100)
	{
		chocolate++;
		if (simulation())
		{
			break;
		}
	}
	cout << chocolate;
	return 0;
}