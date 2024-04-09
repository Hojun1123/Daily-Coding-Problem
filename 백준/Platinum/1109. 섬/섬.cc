#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
#include <sstream>
using namespace std;
int N, M;
string arr[50];
int dy[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
// 만약 어떤 섬이 다른 섬을 포함하고 있지 않으면 > 높이 0
// dfs를 돌면서 bfs?
// 섬의 높이 0 ... H
int area[50][50];
int check[50][50];
int areaCnt = 0;
int answer[1000];
struct yx {
	int y, x;
};
void ff(int yy, int xx)
{
	queue<yx> qq;
	qq.push({ yy, xx });
	area[yy][xx] = areaCnt;
	while (!qq.empty()) {
		for (int i = 0; i < 8; ++i) {
			int y = dy[i] + qq.front().y;
			int x = dx[i] + qq.front().x;
			if (x < 0 || y < 0 || y >= N || x >= M || area[y][x] || arr[y][x] == '.') continue;
			area[y][x] = areaCnt;
			qq.push({ y, x });
		}
		qq.pop();
	}
}
void initArea()
{
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 'x' && area[i][j] == 0) {
				areaCnt++;
				ff(i, j);
			}
		}
	}
	//for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) { cout << area[i][j]; } cout << "\n"; }
}
int dfs(int height, int num)
{
	queue<yx> q;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (area[i][j] == num) {
				q.push({ i, j });
				check[i][j] = height;
			}
		}
	}
	unordered_set<int> ms;
	while (!q.empty())
	{
		yx now = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int y = dy[k] + now.y;
			int x = dx[k] + now.x;
			if (y < 0 || x < 0 || x >= M || y >= N || check[y][x]) continue;
			if (area[y][x] > 0) ms.insert(area[y][x]);
			else q.push({ y, x });
			check[y][x] = height;
		}
	}

	int maxHeight = 0;
	for (auto i : ms) {
		int r = dfs(height + 1, i);
		maxHeight = max(maxHeight, r);
	}
	answer[maxHeight]++;
	return maxHeight + 1;
}
void calHeight()
{
	queue<yx> q;
	for (int i = 0; i < N; ++i)
	{
		q.push({ i, -1 });
		q.push({ i, M });
	}
	for (int j = 0; j < M; ++j)
	{
		q.push({ -1, j });
		q.push({ N, j });
	}

	unordered_set<int> ms;
	while (!q.empty())
	{
		yx now = q.front();
		q.pop();
		for (int k = 0; k < 4; ++k)
		{
			int y = dy[k] + now.y;
			int x = dx[k] + now.x;
			if (y < 0 || x < 0 || x >= M || y >= N || check[y][x]) continue;
			if (area[y][x] > 0) ms.insert(area[y][x]);
			else q.push({ y, x });
			check[y][x] = 1;
		}
	}
	//for (auto i : ms) cout << i << ' '; cout << "\n";
	int maxHeight = 0;
	for (auto i : ms) {
		int r = dfs(2, i);
		maxHeight = max(maxHeight, r);
	}
	//answer[maxHeight] ++;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	//A 와 B 가 다르고, B의 어느 곳에서 출발해도 A의 밖으로 나갈 수 없을 때.
	//B에서 탐색을 시작해도 A의 밖으로 나갈수 없을 경우..?
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	initArea();
	calHeight();
	//for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) { cout << check[i][j]; } cout << "\n"; }
	int index = 0;
	stack<int> st;
	while (answer[index]) {
		cout << answer[index++] << " ";
	}
	if (index == 0) cout << -1;
	return 0;
}