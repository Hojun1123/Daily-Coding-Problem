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

typedef struct yx {
	int y;
	int x;
} yx;
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;

	int N;
	int arr[15][15];
	yx startPoint, endPoint;
	int dy[4] = { 0, 0, 1, -1 };
	int dx[4] = { 1, -1, 0, 0 };
	int checkVisited[15][15];
	cin >> T;
	int time = 0;
	for (int t = 1; t <= T; ++t)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> arr[i][j];
				checkVisited[i][j] = 0;
			}
		}

		cin >> startPoint.y >> startPoint.x;
		cin >> endPoint.y >> endPoint.x;

		queue<yx> q;
		int y, x, ay, ax;
		int qSize;
		int time = 0;
		bool pCheck;
		q.push(startPoint);
		int answer = -1;
		while (!q.empty())
		{
			qSize = q.size();
			//cout << "\n" << time << " : ";
			for (int i = 0; i < qSize; ++i)
			{
				pCheck = true;
				y = q.front().y;
				x = q.front().x;
				q.pop();
				checkVisited[y][x] = 1;
				//cout << y << " " << x << "   ";
				if (endPoint.y == y && endPoint.x == x)
				{
					q = queue<yx>();
					answer = time;
					break;
				}
				for (int k = 0; k < 4; ++k)
				{
					ay = y + dy[k];
					ax = x + dx[k];
					if (ax >= 0 && ax < N && ay >= 0 && ay < N && checkVisited[ay][ax] == 0)
					{
						if (arr[ay][ax] == 0 || (arr[ay][ax] == 2 && time % 3 == 2))
						{
							q.push({ ay, ax });
							checkVisited[ay][ax] = 1;
						}
						else if (arr[ay][ax] == 2 && pCheck)
						{
							q.push({ y, x });
							checkVisited[y][x] = 0;
							pCheck = false;
						}
					}
				}
			}
			time++;
		}
		cout << "#" << t << " " << answer << "\n";
	}
	return 0;
}