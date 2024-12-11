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
//정원은 땅, 호수
//인건비 절감을 위해 초록색/빨간색 배양액을 사용해서 꽃을 뿌리고
//배양액 땅은 정해져 있음
//매초 퍼져나감
//동시에 합쳐져야댐 -> 꽃
//0호수, 1배양액X, 2배양액
int N, M, G, R;
int arr[50][50];
int dy[4] = { 1, -1, 0 ,0 };
int dx[4] = { 0, 0, 1, -1 };
int answer = 0;
struct yx { int y, x; };
vector<yx> vec;
vector<int> r, g;
//R + G는 10 이하니, r과 g에 대해 정수 키로 check.
void btr(int index, int cnt, int curr) {
	if (vec.size() - index + cnt < R) return;
	if (cnt > R) return;
	if (index == vec.size()) {
		if (cnt == R) {
			r.push_back(curr);
		}
		return;
	}
	btr(index + 1, cnt, curr);
	btr(index + 1, cnt + 1, curr | (1 << index));
}
void btg(int index, int cnt, int curr) {
	if (vec.size() - index + cnt < G) return;
	if (cnt > G) return;
	if (index == vec.size()) {
		if (cnt == G) {
			g.push_back(curr);
		}
		return;
	}
	btg(index + 1, cnt, curr);
	btg(index + 1, cnt + 1, curr | (1 << index));
}
int visited[50][50];
void simulation(int rb, int gb) {
	queue<yx> q1;
	queue<yx> q2;
	memset(visited, 0, sizeof(visited));
	for (int i = 1; i <= vec.size(); i++) {
		if (rb & 1) {
			q1.push(vec[i - 1]);
			visited[vec[i - 1].y][vec[i - 1].x] = 4;
		}
		else if (gb & 1) {
			q2.push(vec[i - 1]);
			visited[vec[i - 1].y][vec[i - 1].x] = 4;
		}
		rb >>= 1;
		gb >>= 1;
	}

	int flower = 0;
	while (!q1.empty() && !q2.empty()) {
		int qSize = q1.size();
		for (int i = 0; i < qSize; ++i) {
			yx now = q1.front();
			q1.pop();
			if (visited[now.y][now.x] == 3) continue;
			for (int k = 0; k < 4; ++k) {
				int y = dy[k] + now.y;
				int x = dx[k] + now.x;
				if (x < 0 || y < 0 || x >= M || y >= N) continue;
				if (arr[y][x] == 0) continue;
				if (visited[y][x] == 0) {
					visited[y][x] = 1;
					q1.push({ y, x });
				}
				else if (visited[y][x] == 2) {
					visited[now.y][now.x] = 3;
				}
			}
		}
		
		qSize = q2.size();
		for (int i = 0; i < qSize; ++i) {
			yx now = q2.front();
			q2.pop();
			for (int k = 0; k < 4; ++k) {
				int y = dy[k] + now.y;
				int x = dx[k] + now.x;
				if (x < 0 || y < 0 || x >= M || y >= N) continue;
				if (arr[y][x] == 0) continue;
				if (visited[y][x] == 1) {
					flower++;
					visited[y][x] = 3;
				}
				else if(visited[y][x] == 0) {
					visited[y][x] = 2;
					q2.push({ y, x });
				}
			}
		}
	}
	/*
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << visited[i][j] << " ";
		}cout << "\n";
	}cout << "\n";
	*/
	answer = max(answer, flower);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) vec.push_back({ i, j });
		}
	}
	btr(0, 0, 0);
	btg(0, 0, 0);
	//for (int i : r) cout << i << " ";
	//for (int i : g) cout << i << " ";
	for (int i = 0; i < r.size(); ++i) {
		for (int j = 0; j < g.size(); ++j) {
			if (r[i] & g[j]) continue;
			simulation(r[i], g[j]);
		}
	}
	cout << answer;
	return 0;
}