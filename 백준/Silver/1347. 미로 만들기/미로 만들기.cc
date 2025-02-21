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
int N;
string a;
int arr[101][101];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> a;
	int sy = 50;
	int sx = 50;
	int dir = 0;
	int maxx = sx;
	int maxy = sy;
	int minx = sx;
	int miny = sy;
	//아 왼 위 오
	arr[sy][sx] = '.';
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == 'F') {
			sy += dy[dir];
			sx += dx[dir];
			arr[sy][sx] = 1;
			maxx = max(maxx, sx);
			maxy = max(maxy, sy);
			minx = min(minx, sx);
			miny = min(miny, sy);
		}
		else if (a[i] == 'R') {
			//시계
			dir = (4 + dir + 1) % 4;
		}
		else if (a[i] == 'L') {
			//반시계
			dir = (4 + dir - 1) % 4;
		}
	}

	for (int i = miny; i <= maxy; ++i) {
		for (int j = minx; j <= maxx; ++j) {
			cout << (arr[i][j] ? "." : "#");
		}
		cout << "\n";
	}
	return 0;
}