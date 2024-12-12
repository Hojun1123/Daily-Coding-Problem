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
struct Node {
	int n, c;
};
vector<Node> graph[100001];
int visited[100001];
queue<Node> qq;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int input, a, b;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> a;
		while (true) {
			cin >> input;
			if (input == -1) break;
			cin >> b;
			graph[a].push_back({ input, b });
		}
	}
	qq.push({ 1, 0 });
	visited[1] = 1;
	Node last = { 0, -1 };
	while (!qq.empty()) {
		int qs = qq.size();
		for (int i = 0; i < qs; ++i) {
			Node curr = qq.front(); qq.pop();
			if (curr.c > last.c) {
				last = curr;
			}
			for (int k = 0; k < graph[curr.n].size(); ++k) {
				int nxt = graph[curr.n][k].n;
				int nxtCost = graph[curr.n][k].c + curr.c;
				if (visited[nxt]) continue;
				visited[nxt] = 1;
				qq.push({ nxt, nxtCost });
			}
		}
	}

	memset(visited, 0, sizeof(visited));
	int mv = 0;
	qq.push({last.n, 0});
	visited[last.n] = 1;
	while (!qq.empty()) {
		int qs = qq.size();
		for (int i = 0; i < qs; ++i) {
			Node cc = qq.front();
			mv = max(mv, cc.c);
			qq.pop();
			for (int k = 0; k < graph[cc.n].size(); ++k) {
				Node nxt = graph[cc.n][k];
				int nxtCost = nxt.c + cc.c;
				if (visited[nxt.n]) continue;
				visited[nxt.n] = 1;
				qq.push({ nxt.n, nxtCost });
			}
		}
	}

	cout << mv;
	return 0;
}