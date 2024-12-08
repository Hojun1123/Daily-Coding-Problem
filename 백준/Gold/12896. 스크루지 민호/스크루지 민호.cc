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
int N;
vector<int> graph[100001];
int visited[100001];
queue<int> q;
int pv = 1;
int bfs(int n) {
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int qs = q.size();
		for (int k = 0; k < qs; ++k) {
			int now = q.front();
			pv = now;
			q.pop();
			for (int i = 0; i < graph[now].size(); ++i) {
				int nxt = graph[now][i];
				if (visited[nxt]) continue;
				visited[nxt] = 1;
				q.push(nxt);
			}
		}
		cnt++;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; ++i) {
		int a, b; 
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bfs(1);
	cout << (bfs(pv) / 2);
	return 0;
}