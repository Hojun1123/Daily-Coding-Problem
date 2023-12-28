#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <list>
#include <cmath>
using namespace std;

int N;
typedef struct yx {
	int y;
	int x;

}yx;
int arr[27][27];
int check[27][27];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	string a;
	for (int i = 1; i <= N; ++i)
	{
		cin >> a;
		for (int j = 0; j < a.size(); ++j)
		{
			arr[i][j + 1] = (a[j] == '1' ? 1 : 0);
		}
	}

	int ax[4] = { 1, -1, 0, 0 };
	int ay[4] = { 0, 0, 1, -1 };
	int x, y, dx, dy;
	stack<yx> s;
	priority_queue<int, vector<int>, greater<int>> q;
	int cnt;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (arr[i][j] == 1 && check[i][j] == 0)
			{
				s.push({ i, j });
				check[i][j] = 1;
				cnt = 0;
				while (!s.empty())
				{
					y = s.top().y;
					x = s.top().x;
					cnt++;
					s.pop();
					for (int k = 0; k < 4; ++k)
					{
						dy = y + ay[k];
						dx = x + ax[k];
						if (arr[dy][dx] == 1 && check[dy][dx] == 0)
						{
							s.push({ dy, dx });
							check[dy][dx] = 1;
						}
					}
				}
				q.push(cnt);
			}
		}
	}
	cout << q.size() << "\n";
	while (!q.empty())
	{
		cout << q.top() << "\n";
		q.pop();
	}
	return 0;
}

