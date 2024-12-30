#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int T, W, H;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
char room[20][20];
// 1 2 4 8 16 , 32 64 128 256 512
int visited[20][20][1024];
typedef struct yx {
	int y, x;
	int curr;
} yx;
typedef struct queue {
	int front;
	int back;
	int size;
	yx data[40000];
} queue;
void init(queue *ptr) {
	ptr->back = -1;
	ptr->front = 0;
	ptr->size = 0;
}
void push(queue* ptr, yx* data) {
	ptr->back = (ptr->back + 1) % 40000;
	ptr->data[ptr->back] = *data;
	ptr->size++;
}
yx pop(queue* ptr) {
	yx ret = ptr->data[ptr->front];
	ptr->front = (ptr->front + 1) % 40000;
	ptr->size--;
	return ret;
}
int hash[20][20];
queue q;
int main()
{
	while (1) {
		memset(visited, 0, sizeof(visited));
		memset(hash, 0, sizeof(hash));
		init(&q);
		scanf("%d %d", &W, &H);
		if (!W)break;
		int hashIndex = 1;
		for (int i = 0; i < H; ++i) {
			scanf("%s", room[i]);
			//. 깨끗, *더러운, x가구, o시작 위치
			//더러운 칸은 10개를 넘지 않음 -> 각 더러운칸의 상태를 집합으로 가지면서 탐색 ㄱㄱ
			for (int j = 0; j < W; ++j) {
				if (room[i][j] == '*') {
					hash[i][j] = hashIndex;
					hashIndex <<= 1;
				}
				else if (room[i][j] == 'o') {
					yx tmp = { i, j, 0 };
					push(&q, &tmp);
				}
			}
		}

		//search...
		hashIndex--;
		int ans = 0;
		int flag = 0;
		while (q.size) {
			int qSize = q.size;
			for (int i = 0; i < qSize; ++i) {
				yx now = pop(&q);
				if (now.curr == hashIndex) {
					q.size = 0;
					flag = 1;
					break;
				}
				for (int k = 0; k < 4; ++k) {
					int y = dy[k] + now.y;
					int x = dx[k] + now.x;
					if (x < 0 || y < 0 || x >= W || y >= H) continue;
					if (room[y][x] == 'x') continue;
					int nxt = now.curr | hash[y][x];
					if (visited[y][x][nxt]) continue;
					visited[y][x][nxt] = 1;
					yx tmp = { y, x, nxt };
					push(&q, &tmp);
				}
			}
			ans++;
		}
		printf("%d\n", (flag ? ans-1 : -1));
	}
	return 0;
}