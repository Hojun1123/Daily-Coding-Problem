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
int N, M, X, Y;
//속도가 가속되기도 하고 감속되기도 함
struct Node {
	int n;
	long long c;
	bool operator<(Node o)const {
		return c > o.c;
	}
};
vector<Node> graph[1001];
priority_queue<Node> pq;
long long ans[1001];
void dijkstra(int s)
{
	for (int i = 0; i < N; ++i) ans[i] = 99992100000000;
	ans[s] = 0;
	pq.push({ s, 0 });

	while (!pq.empty())
	{
		Node now = pq.top();
		pq.pop();
		if (now.c > ans[now.n]) continue;
		for (int i = 0; i < graph[now.n].size(); ++i)
		{
			Node nxt = graph[now.n][i];
			long long nxtCost = nxt.c + ans[now.n];
			if (nxtCost >= ans[nxt.n]) continue;
			ans[nxt.n] = nxtCost;
			pq.push({ nxt.n, nxtCost });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M >> X >> Y;
	int a, b, c;
	for (int i = 0; i < M; ++i)
	{
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	//하루에 X보다 먼 거리를 걷지 않고, 거리가 가까운 집부터 방문.
	//내 집은 Y
	dijkstra(Y);
	
	sort(ans, ans + N);

	//for (int i = 0; i < N; ++i) cout << ans[i] << ", ";
	//cout << "\n";
	int answer = 1;
	long long cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		long long curr = ans[i] * 2;
		if (curr > X) {
			cout << -1;
			return 0;
		}

		if (cnt + curr <= X)
		{
			cnt += curr;
		}
		else
		{
			answer++;
			cnt = curr;
		}
	}
	cout << answer;
	return 0;
}