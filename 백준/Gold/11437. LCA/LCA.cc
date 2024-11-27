#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int N, M;
vector<int> graph[50001];
int level[50001];
int parent[50001];
queue<int> q;
void lca(int a, int b) {
	int av = a;
	int bv = b;
	while (av != bv) {
		if (level[av] < level[bv]) {
			bv = parent[bv];
		}
		else {
			av = parent[av];
		}
	}
	cout << av << "\n";
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
	q.push(1);
	level[1] = 1;
	int cnt = 2;
	while (!q.empty()) {
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i) {
			int curr = q.front();
			q.pop();
			for (int k = 0; k < graph[curr].size(); ++k) {
				if (level[graph[curr][k]]) continue;
				q.push(graph[curr][k]);
				level[graph[curr][k]] = cnt;
				parent[graph[curr][k]] = curr;
			}
		}
		cnt++;
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		lca(a, b);
	}

	return 0;
}