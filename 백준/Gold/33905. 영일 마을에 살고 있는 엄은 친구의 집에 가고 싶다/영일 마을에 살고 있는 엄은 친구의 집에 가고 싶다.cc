#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
int N, M, K;
vector<int> vec[5005];
int check[5005];
queue<int> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// n + 1개의 집이 M개의 도로
	//엄은 1번 친구들은 2 ~ n+1
	//k명은 문을 잠갔음
	cin >> N >> M >> K;
	int a, b;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for (int i = 0; i < K; ++i)
	{
		cin >> a;
		check[a] = 1;
	}
	q.push(1);
	check[1] = 1;
	int ans = 0;
	while (!q.empty())
	{
		int qs = q.size();
		for (int k = 0; k < qs; ++k)
		{
			int now = q.front();
			q.pop();
			for (int i = 0; i < vec[now].size(); ++i)
			{
				int nxt = vec[now][i];
				if (check[nxt])
				{
					continue;
				}
				check[nxt] = 1;
				q.push(nxt);
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}