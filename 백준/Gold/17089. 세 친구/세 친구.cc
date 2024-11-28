#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int N, M;
//N명, 관계 M
vector<int> graph[4001];
vector<int> f;
int g[4001][4001];
int ans = 987654321;
void bt(int index, int cnt) {
	if (cnt == 3) {
		//for (int i = 0; i < f.size(); ++i)cout << f[i] << " "; cout << "\n";
		ans = min(ans, int(graph[f[0]].size() + graph[f[1]].size() + graph[f[2]].size()) - 6);
		return;
	}
	for (int i = index + 1; i <= N; ++i) {
		if (cnt == 1 && g[f[0]][i] == 0) continue;
		else if (cnt == 2 && (g[f[0]][i] == 0 || g[f[1]][i] == 0)) continue;
		f.push_back(i);
		bt(i, cnt + 1);
		f.pop_back();
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
		g[a][b] = 1;
		g[b][a] = 1;
	}
	bt(-1, 0);
	cout << (ans == 987654321 ? -1 : ans);
	return 0;
}