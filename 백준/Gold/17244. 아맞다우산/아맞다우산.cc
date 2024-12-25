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
int N, M;
// 비어있는곳은., 벽은#, 
// 챙겨야하는 물건은 최대 5개. -> 1 2 4 8 16
struct Node {
	int y, x, bv;
};
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
queue<Node> q;
string arr[50];
int check[50][50][32];
int bp[50][50];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> M >> N;
	int bb = 1;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
		for (int j = 0; j < M; ++j) {
			if (arr[i][j] == 'S') {
				q.push({ i, j, 0 });
				check[i][j][0] = 1;
			}
			else if (arr[i][j] == 'X') {
				bp[i][j] = bb;
				bb <<= 1;
			}
		}
	}
	int sc = 0;
	for (int i = 1; i < bb; i <<= 1) {
		sc |= i;
	}
	int ans = 0;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i) {
			Node curr = q.front();
			q.pop();
			if (arr[curr.y][curr.x] == 'E' && !(sc ^ curr.bv)) {
				cout << ans;
				return 0;
			}
			for (int k = 0; k < 4; ++k) {
				int y = dy[k] + curr.y;
				int x = dx[k] + curr.x;
				if (x < 0 || y < 0 || x >= M || y >= N) continue;
				if (arr[y][x] == '#') continue;
				if (arr[y][x] == 'X') {
					if (check[y][x][curr.bv | bp[y][x]] == 0) {
						check[y][x][curr.bv | bp[y][x]] = 1;
						q.push({ y, x, curr.bv | bp[y][x] });
					}
				}
				else {
					if (check[y][x][curr.bv] == 0) {
						check[y][x][curr.bv] = 1;
						q.push({ y, x, curr.bv });
					}
				}
			}
		}
		ans++;
	}
 	return 0;
}
