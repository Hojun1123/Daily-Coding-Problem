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
//25명, 5x5
// 이다솜과 임도연
// 7명, 아무나 구성이지만 이다솜파가 더 많아야함
//s다솜, y도연
//25 24 23 22 21 20 19
bool visited[40000000];
vector<int> ret;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int arr[5][5];
int ans = 0;
int check[5][5];
struct yx {
	int y, x;
};
vector<yx> q;
//시작y, x, 비트
void bt(int sy, int sx, int curr, int pick, int sc) {
	if (pick == 7) {
		ans += sc > 3;
		return;
	}
	for (int i = 0; i < q.size(); ++i) {
		yx now = q[i];
		for (int k = 0; k < 4; ++k) {
			int y = dy[k] + now.y;
			int x = dx[k] + now.x;
			if (x < 0 || y < 0 || x >= 5 || y >= 5) continue;
			if (check[y][x]) continue;
			int nb = curr | (1 << (y * 5 + x));
			if (visited[nb]) continue;
			visited[nb] = 1;
			check[y][x] = 1;
			q.push_back({ y, x });
			bt(y, x, nb, pick + 1, sc + arr[y][x]);
			check[y][x] = 0;
			q.pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a;
	for (int i = 0; i < 5; ++i) {
		cin >> a;
		for (int j = 0; j < 5; ++j) arr[i][j] = (a[j] == 'S' ? 1 : 0);
	}
	int cnt = 0;
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			q.push_back({ i, j });
			check[i][j] = 1;
			bt(i, j, 1 << cnt, 1, arr[i][j]); cnt++;
			q.pop_back();
			check[i][j] = 0;
		}
	}
	cout << ans;
	return 0;
}