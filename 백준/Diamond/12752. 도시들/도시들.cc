#include <vector>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
#include <map>
#include <cmath>
#include <deque>
using namespace std;
int N, K, M;
struct Node {
	int n;
	long long cost;
	bool operator<(const Node& o) const {
		return cost > o.cost;
	}
};
priority_queue<Node> pq;
long long ret[5][200001];
vector<Node> graph[200001];
int hashMap[5];
void dijkstra(int index) {
	int start = hashMap[index];
	for (int i = 1; i <= N; ++i) {
		//10^15
		ret[index][i] = 1000000000000000;
	}

	pq.push({ start, 0 });
	ret[index][start] = 0;
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.cost > ret[index][now.n]) continue;
		for (int i = 0; i < graph[now.n].size(); ++i) {
			Node nxt = graph[now.n][i];
			long long nxtCost = nxt.cost + ret[index][now.n];
			if (nxtCost >= ret[index][nxt.n]) continue;
			ret[index][nxt.n] = nxtCost;
			pq.push({ nxt.n, nxtCost });
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> M;
	int bb = 1;
	for (int i = 0; i < K; ++i) {
		// 각 인덱스를 매치
		cin >> hashMap[i];
		bb <<= 1;
	}
	for (int i = 0; i < M; ++i) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	for (int i = 0; i < K; ++i) {
		dijkstra(i);
	}

	int minIndex = 0;
	long long minCost = 5000000000000000;
	for (int i = 1; i <= N; ++i) {
		long long currCost = ret[0][i] + ret[1][i] + ret[2][i] + ret[3][i] + ret[4][i];
		if (minCost > currCost) {
			minCost = currCost;
			minIndex = i;
		}
	}

	cout << minCost;
	return 0;
}