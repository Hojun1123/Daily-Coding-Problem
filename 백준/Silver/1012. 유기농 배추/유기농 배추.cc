#include <iostream>
#include <queue>
#include <stack>
#include <map>
using namespace std;
int M, N, K, T;
typedef struct yx
{
	int y;
	int x;
};
int main() {
	cin >> T;
	for (int t = 0; t < T; ++t)
	{
		cin >> M;
		cin >> N;
		cin >> K;
		int arr[50][50];
		int check[50][50];
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				arr[i][j] = 0;
				check[i][j] = 0;
			}
		}


		int x, y;
		for (int j = 0; j < K; ++j)
		{
			cin >> x;
			cin >> y;
			arr[y][x] = 1;
		}

		stack<yx> s;
		int ax[4] = { 1, -1, 0, 0 };
		int ay[4] = { 0, 0, 1, -1 };
		int dy, dx;
		int answer = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (arr[i][j] == 1 && check[i][j] == 0)
				{
					s.push({ i, j });
 					answer += 1;
				}
				while (!s.empty())
				{
					y = s.top().y;
					x = s.top().x;
					s.pop();
					check[y][x] = 1;
					for (int k = 0; k < 4; ++k)
					{
						dy = y + ay[k];
						dx = x + ax[k];
						if (dy >= 0 && dy < N && dx >= 0 && dx < M && check[dy][dx] == 0 && arr[dy][dx] == 1)
						{
							s.push({ dy, dx });
						}
					}
				}
			}
		}
		cout << answer << "\n";
	}
	return 0;
}
