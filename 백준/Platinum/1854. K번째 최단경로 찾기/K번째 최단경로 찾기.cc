#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;
int N, M, K;
struct Node {
	int n;
	long long c;
	bool operator<(Node o) const {
		return c > o.c;
	}
};
vector<Node> graph[1001];
priority_queue<Node> pq;
priority_queue<long long> ret[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}
	ret[1].push(0);
	pq.push({ 1, 0 });
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		for (int i = 0; i < graph[now.n].size(); ++i) {
			Node nxt = graph[now.n][i];
			long long nxtCost = nxt.c + now.c;
			if (ret[nxt.n].size() >= K) {
				if (ret[nxt.n].top() > nxtCost) {
					ret[nxt.n].pop();
					ret[nxt.n].push(nxtCost);
					pq.push({ nxt.n, nxtCost });
				}
			}
			else {
				ret[nxt.n].push(nxtCost);
				pq.push({ nxt.n, nxtCost });
			}
			//cout << nxtCost << " ";
		}
	}
	for (int i = 1; i <= N; ++i) {
		if (ret[i].size() < K) {
			cout << -1 << "\n";
			continue;
		}
		for (int j = 0; j < ret[i].size() - K; ++j) ret[i].pop();
		cout << ret[i].top() << "\n";
	}
	return 0;
}