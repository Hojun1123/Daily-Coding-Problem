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
int N, M;
struct Node {
	int n;
	int cost;
	bool operator<(const Node &o) const {
		return cost > o.cost;
	}
};
struct p {
	int a, b;
};
vector<p> v;
vector<Node> graph[1001];
int answer[3][1001];
vector<int> path[3][1001];
priority_queue<Node> pq;
int person[3];
void dijkstra(int index) {
	int start = person[index];
	pq.push({ start, 0 });
	answer[index][start] = 0;
	while (!pq.empty()) {
		Node now = pq.top();
		pq.pop();
		if (now.cost > answer[index][now.n]) continue;
		for (int i = 0; i < graph[now.n].size(); ++i) {
			Node nxt = graph[now.n][i];
			int nxtCost = nxt.cost + answer[index][now.n];
			if (nxtCost > answer[index][nxt.n]) continue;
			if (nxtCost == answer[index][nxt.n]) {
				path[index][nxt.n].push_back(now.n);
			}
			else {
				path[index][nxt.n].clear();
				path[index][nxt.n].push_back(now.n);
				answer[index][nxt.n] = nxtCost;
			}
			pq.push({ nxt.n, nxtCost });
		}
	}
	//for (int i = 1; i <= N; ++i) cout << answer[index][i] << ", "; cout << "\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}
	for (int i = 0; i < 3; ++i) {
		cin >> person[i];
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 1; j <= N; ++j) {
			answer[i][j] = 1987654321;
		}
	}
	for (int i = 0; i < 3; ++i) {
		dijkstra(i);
	}

	int minIndex = 1;
	long long minValue = 11987654321;
	for (int i = 1; i <= N; ++i) {
		long long currCost = (long long)answer[0][i] + (long long)answer[1][i] + (long long)answer[2][i];
		if (minValue > currCost) {
			minValue = currCost;
			minIndex = i;
		}
	}

	// print
	cout << minValue << " ";
	
	// cnt
	for (int i = 0; i < 3; ++i) {
		int start;
		for (start = minIndex; start != person[i]; start = path[i][start][0]) {
			v.push_back({ start, path[i][start][0] });
		}
	}
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i].a << " " << v[i].b << "\n";
	}
 	return 0;
}