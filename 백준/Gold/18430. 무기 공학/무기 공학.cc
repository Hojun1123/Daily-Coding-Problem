#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
// 무기 공학
//14 + 8 + 18 + 6 = 46
int N, M;
int arr[5][5];
int visited[5][5];
int ans = 0;
int dy[4][3] = { {-1,0,0},{0,0,1},{0,0,1},{-1,0,0} };
int dx[4][3] = { {0,0,1},{0,1,0},{-1,0,0},{0,0,-1} };
void bt(int _y, int _x, int _score)
{
	ans = max(_score, ans);
	if (_y == N) {
		return;
	}
	if (_x == M) {
		bt(_y + 1, 0, _score);
		return;
	}
	if (visited[_y][_x]) {
		bt(_y, _x + 1, _score);
	}
	else {
		for (int k = 0; k < 4; ++k) {
			int ia = 1;
			for (int i = 0; i < 3; ++i) {
				int y = _y + dy[k][i];
				int x = _x + dx[k][i];
				if (x < 0 || y < 0 || x >= M || y >= N) {
					ia = 0;
					break;
				}
				if (visited[y][x]) {
					ia = 0;
					break;
				}
			}
			if (ia) {
				int score = 0;
				for (int i = 0; i < 3; ++i) {
					int y = _y + dy[k][i];
					int x = _x + dx[k][i];
					score += arr[y][x];
					visited[y][x] = 1;
				}
				bt(_y, _x + 1, _score + score + arr[_y][_x]);
				for (int i = 0; i < 3; ++i) {
					visited[_y + dy[k][i]][_x + dx[k][i]] = 0;
				}
			}
		}
		bt(_y, _x + 1, _score);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M; for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cin >> arr[i][j]; }
	
	// y x score
	bt(0, 0, 0);

	cout << ans;
	return 0;
}