#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
int T;
int K, W, H;
struct Node {
	int y, x, c;
	bool operator<(Node o)const {
		return c > o.c;
	}
};
priority_queue<Node> pq;
int cost[144];
int answer[1000][1000];
string arr[1000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
void solve() {
	//전투선의 클래스 개수? , 폭, 높이
	cin >> K >> W >> H;
	for (int i = 0; i < K; ++i) {
		char a;
		int b;
		cin >> a >> b;
		cost[a] = b;
	}
	int sy, sx;
	for (int i = 0; i < H; ++i) {
		cin >> arr[i];
		for (int j = 0; j < W; ++j) {
			if (arr[i][j] == 'E') {
				sy = i;
				sx = j;
			}
			answer[i][j] = 2100000000;
		}
	}
	pq.push({ sy, sx, 0 });
	answer[sy][sx] = 0;
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.c > answer[now.y][now.x]) continue;
		if (now.y == 0 || now.y == H - 1 || now.x == 0 || now.x == W - 1) {
			cout << answer[now.y][now.x] << "\n";
			pq = priority_queue<Node>();
			return;
		}
		for (int i = 0; i < 4; ++i) {
			int y = now.y + dy[i];
			int x = now.x + dx[i];
			if (x < 0 || y < 0 || x >= W || y >= H)continue;
			int nxtCost = now.c + cost[arr[y][x]];
			if (nxtCost >= answer[y][x]) continue;
			pq.push({ y, x, nxtCost });
			answer[y][x] = nxtCost;
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> T;
	for (int i = 0; i < T; ++i) {
		solve();
	}
	return 0;
}
