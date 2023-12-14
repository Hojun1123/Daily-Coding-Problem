#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

typedef struct yx
{
	int y;
	int x;
} yx;
int N, M;
char table[600][600];
int check[600][600];
stack<yx> s;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> M;
	string l;
	for (int i = 0; i < N; ++i)
	{
		cin >> l;
		for (int j = 0; j < M; ++j)
		{
			table[i][j] = l[j];
			if (l[j] == 'I')
			{
				s.push({ i, j });
				check[i][j] = 1;
			}
		}
	}

	int ax[4] = { 1, -1, 0, 0 };
	int ay[4] = { 0, 0, 1, -1 };
	int x, y, dx, dy;
	int cnt = 0;
	while (!s.empty())
	{
		y = s.top().y;
		x = s.top().x;
		s.pop();
		if (table[y][x] == 'P' && check[y][x] == 0)
		{
			cnt += 1;
		}
		check[y][x] = 1;

		for (int i = 0; i < 4; ++i)
		{
			dy = y + ay[i];
			dx = x + ax[i];
			if (dy >= 0 && dy < N && dx >= 0 && dx < M && check[dy][dx] == 0 && table[dy][dx] != 'X')
			{
				s.push({ dy, dx });
			}
		}
	}

	cout << (cnt ? to_string(cnt) : "TT");
	return 0;
}
 