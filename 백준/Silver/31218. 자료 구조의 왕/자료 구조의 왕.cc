#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <map>
using namespace std;

int N, M, Q;
int arr[1000][1000];
int y, x, dy, dx;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> Q;
	int query;
	int cnt = N * M;
	queue<int> ans;
	for (int i = 0; i < Q; ++i)
	{
		cin >> query;
		if (query == 1)
		{
			cin >> dy >> dx >> y >> x;
			y--; x--;
			while (true)
			{
				if (arr[y][x] == 1)
				{
					break;
				}
				arr[y][x] = 1;
				cnt--;
				if (y + dy >= 0 && y + dy < N && x + dx >= 0 && x + dx < M && arr[y + dy][x + dx] == 0)
				{
					y += dy;
					x += dx;
				}
				else {
					break;
				}
			}
		}
		else if (query == 2)
		{
			cin >> y >> x;
			cout << arr[y - 1][x - 1] << "\n";
		}
		else
		{
			cout << cnt << "\n";
		}
	}
	return 0;
}