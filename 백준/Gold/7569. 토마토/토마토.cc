#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int table[102][102][102];
int M, N, H;
typedef struct zyx {
	int z;
	int y;
	int x;
} zyx;
int main() {
	cin >> M;	// x
	cin >> N;	// y
	cin >> H;	// z
	stack<zyx> s;
	int temp;
	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			table[0][i][j] = -1;
			table[H + 1][i][j] = -1;
		}
	}

	for (int i = 0; i <= H + 1; i++)
	{
		for (int j = 0; j <= M + 1; j++)
		{
			table[i][0][j] = -1;
			table[i][N + 1][j] = -1;
		}
	}

	for (int i = 0; i <= H + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			table[i][j][0] = -1;
			table[i][j][M + 1] = -1;
		}
	}

	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			for (int k = 1; k <= M; ++k)
			{
				cin >> temp;
				table[i][j][k] = temp;
				if (temp == 1)
				{
					s.push({ i, j, k });
				}
			}
		}
	}

	int ax[6] = { 1, -1, 0, 0, 0, 0 };
	int ay[6] = { 0, 0, 1, -1, 0 ,0 };
	int az[6] = { 0, 0, 0, 0, 1, -1 };
	int answer = 0;
	while (!s.empty())
	{
		stack<zyx> temp;
		while (!s.empty())
		{
			zyx a = s.top();
			s.pop();
			for (int i = 0; i < 6; i++)
			{
				int dx = a.x + ax[i];
				int dy = a.y + ay[i];
				int dz = a.z + az[i];
				if (table[dz][dy][dx] == 0)
				{
					table[dz][dy][dx] = 1;
					temp.push({ dz, dy, dx });
				}
			}
		}

		while (!temp.empty())
		{
			s.push(temp.top());
			temp.pop();
		}
		answer += 1;
	}

	int cnt = 0;
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			for (int k = 1; k <= M; ++k)
			{
				if (table[i][j][k] == 0)
					cnt += 1;
			}
		}
	}
	
	if (cnt > 0)
		cout << -1;
	else
		cout << answer - 1;
	return 0;
}