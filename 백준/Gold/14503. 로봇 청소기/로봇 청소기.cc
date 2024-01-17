#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#define fori(a) for(int i = 0; i < a; ++i)
#define forj(a) for(int j = 0; j < a; ++j)
using namespace std;
int N, M, r, c, d;
int arr[50][50];
int check[50][50];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
/*
* 현재 칸이 0, 청소
* 현제 칸의 주변 4 칸 중 청소되지 않은 빈칸이 없는 경우
*  - 방향을 유지한 채로 한칸 후진 한 후 1 번으로 감
*  - 후진 불가능하다면, 작동을 멈춤
* 있는 경우
*  - 반시계로 90 회전
*  - 회전 후 청소되지 않은 빈칸인 경우 한 칸 전진
*  - 1 번으로 돌아감
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;	//0123 북동남서
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> arr[i][j];
			check[i][j] = arr[i][j];
		}
	}
	
	int y, x;
	int cnt = 0;
	while (true)
	{
		if (check[r][c] == 0)
		{
			check[r][c] = 1;
			cnt++;
		}

		int checkAround = false;
		for (int k = 0; k < 4; ++k)
		{
			y = r + dy[k];
			x = c + dx[k];
			if (x >= 0 && x < M && y >= 0 && y < N && check[y][x] == 0)
			{
				checkAround = true;
			}
		}

		if (checkAround)
		{
			d -= 1;
			if (d < 0)
			{
				d = 3;
			}

			y = r + dy[d];
			x = c + dx[d];
			if (x >= 0 && x < M && y >= 0 && y < N && check[y][x] == 0)
			{
				r = y;
				c = x;
			}
		}
		else
		{
			y = r - dy[d];
			x = c - dx[d];
			if (x >= 0 && x < M && y >= 0 && y < N && arr[y][x] == 0)
			{
				r = y;
				c = x;
			}
			else
			{
				break;
			}
		}
		
	}
	cout << cnt;
	return 0;
}