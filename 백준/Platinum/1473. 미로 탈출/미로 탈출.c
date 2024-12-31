#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int dl[4] = { 4, 0, 2, 2 };
int dy[4][4] = {
	{1, -1, 0, 0},
	{0, 0, 0, 0},
	{1, -1, 0, 0},
	{0, 0, 0, 0}
};
int dx[4][4] = {
	{0, 0, 1, -1},
	{0, 0, 0, 0},
	{0, 0, 0, 0},
	{1, -1, 0, 0}
};
int N, M;
char input[7][7];
// y, x, 세로, 가로, 위아래(C, 1): 0, 좌우(D, 0): 1
int visited[7][7][128][128];
int arr[7][7];
typedef struct yx {
	int y;
	int x;
	int row;	//회전?
	int col;	//회전?
}yx;
typedef struct queue {
	int front;
	int back;
	int size;
	yx data[100000];
}queue;
queue q;
void push(yx data) {
	q.back = (q.back + 1) % 100000;
	q.data[q.back] = data;
	q.size++;
}
yx pop() {
	yx ret = q.data[q.front];
	q.front = (q.front + 1) % 100000;
	q.size--;
	return ret;
}
int main()
{
	int type[99];
	type['A'] = 0;
	type['B'] = 1;
	type['C'] = 2;// (index + 2) % 4
	type['D'] = 3;
	q.front = 0;
	q.back = -1;
	q.size = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		scanf("%s", input[i]);
		for (int j = 0; j < M; ++j) {
			arr[i][j] = type[input[i][j]];
		}
	}
	yx start = { 0, 0, 0, 0 };
	push(start);
	visited[0][0][0][0] = 1;
	int ans = 0;
	while (q.size) {
		int qSize = q.size;
		for (int i = 0; i < qSize; ++i) {
			// 현재 상태 세팅
			yx now = pop();
			int nowBoard[7][7];
			if (now.y == N - 1 && now.x == M - 1) {
				printf("%d", ans);
				return 0;
			}
			memcpy(nowBoard, arr, sizeof(nowBoard));
			int br = 1;
			for (int yy = 0; yy < N; ++yy) {
				// 회전을 했으면
				if (br & now.row) {
					for (int xx = 0; xx < M; ++xx) {
						if (nowBoard[yy][xx] == 2) {
							nowBoard[yy][xx] = 3;
						}
						else if (nowBoard[yy][xx] == 3) {
							nowBoard[yy][xx] = 2;
						}
					}
				}
				br <<= 1;
			}

			int bc = 1;
			for (int xx = 0; xx < M; ++xx) {
				// 회전을 했으면
				if (bc & now.col) {
					for (int yy = 0; yy < N; ++yy) {
						if (nowBoard[yy][xx] == 2) {
							nowBoard[yy][xx] = 3;
						}
						else if (nowBoard[yy][xx] == 3) {
							nowBoard[yy][xx] = 2;
						}
					}
				}
				bc <<= 1;
			}

			// nxt
			int k = nowBoard[now.y][now.x];
			for (int l = 0; l < dl[k]; ++l) {
				int y = dy[k][l] + now.y;
				int x = dx[k][l] + now.x;
				if (x < 0 || y < 0 || x >= M || y >= N) continue;
				if (visited[y][x][now.row][now.col]) continue;
				if (nowBoard[y][x] == 1) continue;
				if (nowBoard[now.y][now.x] == 0) {
					if (l < 2 && nowBoard[y][x] == 3) continue;
					if (l > 1 && nowBoard[y][x] == 2) continue;
				}
				else if (nowBoard[now.y][now.x] == 2) {
					if (nowBoard[y][x] == 3) continue;
				}
				else if (nowBoard[now.y][now.x] == 3) {
					if (nowBoard[y][x] == 2) continue;
				}

				yx nxt = { y, x, now.row, now.col };
				visited[y][x][now.row][now.col] = 1;
				push(nxt);
			}
			

			//이미 반전했다면 0 1
			int nxtRow = now.row ^ (1 << now.y);
			int nxtCol = now.col ^ (1 << now.x);
			if (visited[now.y][now.x][nxtRow][nxtCol]) continue;
			visited[now.y][now.x][nxtRow][nxtCol] = 1;
			yx nxt = { now.y, now.x, nxtRow, nxtCol };
			push(nxt);
		}
		ans++;
	}
	printf("-1");
	return 0;
}