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
int N, M;
int check[107];
map<int, int> m;
int dp[107];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	cin >> M;
	int a, b;
	for (int i = 0; i < N + M; ++i)
	{
		cin >> a >> b;
		m[a] = b;
	}
	
	queue<int> q;
	q.push(1);
	int curr, temp;
	int qSize;
	int depth = 0;
	while (!q.empty())
	{
		qSize = q.size();
		for (int i = 0; i < qSize; ++i)
		{
			curr = q.front();
			q.pop();
			if (check[curr] == 1 || curr > 100)
				continue;
			check[curr] = 1;
			if (curr == 100)
			{
				cout << depth;
			}
			for (int j = 1; j <= 6; j++)
			{
				temp = curr + j;
				if (check[temp] == 0)
				{
					if (m.find(temp) == m.end())
					{
						q.push(temp);
					}
					else
					{
						q.push(m[temp]);
					}
				}
			}
		}
		depth++;
	}
	return 0;
}