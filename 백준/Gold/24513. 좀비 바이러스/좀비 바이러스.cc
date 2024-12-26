#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>
#include <deque>
using namespace std;
int N, M;//1, 2, 3
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
//1시간
int arr[1000][1000];
int check[1000][1000];
int st[1000][1000];
struct yx {
	int y, x;
};
queue<yx> q1;
queue<yx> q2;
int ans[4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q1.push({ i, j});
				check[i][j] = 4;
			}
			else if (arr[i][j] == 2) {
				q2.push({ i, j});
				check[i][j] = 5;
			}
		}
	}
	
	while (!q1.empty() || !q2.empty())
	{
		int qSize = q1.size();
		for (int i = 0; i < qSize; ++i) {
			yx now = q1.front();
			q1.pop();
			if (st[now.y][now.x]) continue;
			check[now.y][now.x] = 4;
			for (int k = 0; k < 4; ++k) {
				int y = now.y + dy[k];
				int x = now.x + dx[k];
				if (x < 0 || y < 0 || x >= M || y >= N) continue;
				if (arr[y][x] == -1) continue;
				if (check[y][x] == 0) {
					q1.push({ y, x });
					check[y][x] = 1;
				}
			}
		}

		qSize = q2.size();
		for (int i = 0; i < qSize; ++i) {
			yx now = q2.front();
			q2.pop();
			for (int k = 0; k < 4; ++k) {
				int y = now.y + dy[k];
				int x = now.x + dx[k];
				if (x < 0 || y < 0 || x >= M || y >= N) continue;
				if (arr[y][x] == -1) continue;
				if (check[y][x] == 0) {
					q2.push({ y, x });
					check[y][x] = 5;
				}
				else if (check[y][x] == 1) {
					check[y][x] = 3;
					st[y][x] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j){
			if (check[i][j] == 4) ans[1]++;
			else if (check[i][j] == 5) ans[2]++;
			else if (check[i][j] == 3) ans[3]++;
		}
	}
	cout << ans[1] << " " << ans[2] << " " << ans[3];
 	return 0;
}