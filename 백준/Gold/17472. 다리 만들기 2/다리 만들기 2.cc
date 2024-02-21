#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M;
struct yx {
	int y, x;
};
int board[10][10];
int check[10][10];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int fillNum = 0;
struct Node {
	int a, b;
	int cost;
	bool operator<(Node o) const
	{
		return cost < o.cost;
	}
};
vector<Node> nodes;
int arr[10000];
void bfs(int sy, int sx, int f)
{
	queue<yx> q;
	q.push({ sy, sx });
	check[sy][sx] = f;
	while (!q.empty())
	{
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i)
		{
			yx now = q.front();
			q.pop();
			for (int k = 0; k < 4; ++k)
			{
				int y = dy[k] + now.y;
				int x = dx[k] + now.x;
				if (x >= 0 && y >= 0 && y < N && x < M && board[y][x] && check[y][x] == 0)
				{
					check[y][x] = f;
					q.push({ y, x });
				}
			}
		}
	}
}
void FloodFill()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (board[i][j] && check[i][j] == 0)
			{
				fillNum++;
				bfs(i, j, fillNum);
			}
		}
	}
}
void GetDistance()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (check[i][j])
			{
				for (int k = 0; k < 2; ++k)
				{
					int y = i;
					int x = j;
					int cnt = 0;
					while (true)
					{
						y += dy[k];
						x += dx[k];
						if (x < 0 || y < 0 || x >= M || y >= N)
						{
							// 지도를 벗어남
							break;
						}
						if (check[y][x] > 0)
						{
							// 다른 섬을 만나면.
							if (check[y][x] == check[i][j])
							{
								break;
							}
							else
							{
								nodes.push_back({ check[i][j], check[y][x], cnt });
								break;
							}
						}
						cnt++;
					}
				}
			}
		}
	}
}
void init()
{
	for (int i = 1; i <= nodes.size(); ++i)
		arr[i] = i;
}
int Find(int curr)
{
	if (curr == arr[curr]) return curr;
	int ret = Find(arr[curr]);
	arr[curr] = ret;
	return ret;
}
void Union(int a, int b)
{
	int r1 = Find(a);
	int r2 = Find(b);
	if (r1 == r2) return;
	arr[r2] = r1;
}
int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> board[i][j];
		}
	}
	FloodFill();	//check에 영역 별 분리. fillNum : 영역의 개수
	GetDistance();
	sort(nodes.begin(), nodes.end());
	init();
	int sCount = 0;
	int result = 0;
	
	for (int i = 0; i < nodes.size(); ++i)
	{
		int a = nodes[i].a;
		int b = nodes[i].b;
		int cost = nodes[i].cost;
		if (cost < 2) continue;
		if (Find(a) == Find(b)) continue;
		Union(a, b);
		result += cost;
		sCount++;
		if (sCount == fillNum - 1)
			break;
	}
	cout << (sCount == fillNum - 1 ? result : -1);
	return 0;
}