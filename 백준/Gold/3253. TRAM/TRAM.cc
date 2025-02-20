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
int N, A, B;
int ans[101];
struct Node {
	int n, c;
	bool operator<(Node o) const {
		return c > o.c;
	}
};
priority_queue<Node> pq;
vector<Node> graph[101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> A >> B;
	for (int i = 0; i < N; ++i) {
		int p, r;
		cin >> p;
		if (p > 0) {
			cin >> r;
			graph[i + 1].push_back({ r, 0 });
		}
		for (int j = 1; j < p; ++j) {
			cin >> r;
			graph[i + 1].push_back({ r, 1 });
		}
	}

	for (int i = 1; i <= N; ++i) {
		ans[i] = 987653;
	}
	
	pq.push({ A, 0 });
	ans[A] = 0;
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.c > ans[now.n]) continue;
		for (int i = 0; i < graph[now.n].size(); ++i) {
			Node nxt = graph[now.n][i];
			int nc = nxt.c + ans[now.n];
			if (nc >= ans[nxt.n]) continue;
			ans[nxt.n] = nc;
			pq.push({ nxt.n, nc });
		}
	}
	cout << (ans[B] > 90000 ? -1 : ans[B]);
	return 0;
}