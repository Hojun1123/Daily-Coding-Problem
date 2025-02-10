#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
int N, M;
int check[10001];
vector<int> graph[10001];
queue<int> q;
int ret[10001];
int bfs(int n) {
	memset(check, 0, sizeof(check));
	q.push(n);
	check[n] = 1;
	int cnt = 0;
	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; ++i) {
			int now = q.front();
			q.pop();
			for (int k = 0; k < graph[now].size(); ++k) {
				int nxt = graph[now][k];
				if (check[nxt])continue;
				check[nxt] = 1;
				q.push(nxt);
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; ++i) {
		ret[i] = bfs(i);
	}
	vector<int> ans;
	int maxValue = 0;
	for (int i = 1; i <= N; ++i) {
		if (maxValue == ret[i]) {
			ans.push_back(i);
		}
		else if (maxValue < ret[i]) {
			ans.clear();
			ans.push_back(i);
			maxValue = ret[i];
		}
	}
	for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
	return 0;
}