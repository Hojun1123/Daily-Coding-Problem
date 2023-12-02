#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int table[1003][1003];
int M, N;
typedef struct yx {
	int y;
	int x;
} yx;
int main() {
	cin >> M;	// x
	cin >> N;	// y
	stack<yx> s;
	int temp;
	for (int i = 0; i <= M + 1; i++)
	{
		table[0][i] = -1;
		table[N + 1][i] = -1;
	}
	for (int i = 0; i <= N + 1; i++)
	{
		table[i][0] = -1;
		table[i][M + 1] = -1;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> temp;
			table[i][j] = temp;
			if (temp == 1)
			{
				s.push({ i, j });
			}
		}
	}

	int ax[4] = { 1, -1, 0, 0 };
	int ay[4] = { 0, 0, 1, -1 };
	int answer = 0;
	while (!s.empty())
	{
		stack<yx> temp;
		while (!s.empty())
		{
			yx a = s.top();
			s.pop();
			for (int i = 0; i < 4; i++)
			{
				int dx = a.x + ax[i];
				int dy = a.y + ay[i];
				if (table[dy][dx] == 0)
				{
					table[dy][dx] = 1;
					temp.push({ dy, dx });
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
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (table[i][j] == 0)
				cnt += 1;
		}
	}

	if (cnt > 0)
		cout << -1;
	else
		cout << answer - 1;
	return 0;
}