#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>

typedef struct yx {
	int y;
	int x;
} yx;

using namespace std;
int arr[1002][1002];
int check[1002][1002];
queue<yx> q;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	int a;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a;
			arr[i][j] = a;
			if (a == 2)
			{
				arr[i][j] = 0;
				q.push({ i, j });
			}
			else if (a == 0)
				arr[i][j] = 0;
		}
	}

	int ax[4] = { 1, -1, 0, 0 };
	int ay[4] = { 0, 0, 1, -1 };
	int dx, dy, x, y;

	while (!q.empty())
	{
		y = q.front().y;
		x = q.front().x;
		q.pop();
		check[y][x] = 1;

		for (int i = 0; i < 4; ++i)
		{
			dy = y + ay[i];
			dx = x + ax[i];
			if (check[dy][dx] == 0 && arr[dy][dx] != 0)
			{
				q.push({ dy, dx });
				arr[dy][dx] = arr[y][x] + 1;
				check[dy][dx] = 1;
			}
		}		
	}

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			if (check[i][j] == 0 && arr[i][j] != 0)
				cout << -1 << " ";
			else
				cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}
