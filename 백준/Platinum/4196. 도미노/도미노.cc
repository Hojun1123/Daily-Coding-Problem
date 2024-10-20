#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
int N, M, T;
vector<int> graph[100001];
vector<int> rev[100001];
int visited[100001];
vector<vector<int>> path;
stack<int> s;
queue<int> q;
unordered_map<int, int> um;
int in[100001];
void dfs1(int curr) {
    for (int i = 0; i < graph[curr].size(); ++i) {
        int nxt = graph[curr][i];
        if (visited[nxt]) continue;
        visited[nxt] = 1;
        dfs1(nxt);
    }
    s.push(curr);
}
void dfs2(int curr, int idx) {
    for (int i = 0; i < rev[curr].size(); ++i) {
        int nxt = rev[curr][i];
        if (visited[nxt]) continue;
        path[idx].push_back(nxt);
        um[nxt] = idx;
        visited[nxt] = 1;
        dfs2(nxt, idx);
    }
}
void solve() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        graph[i].clear();
        rev[i].clear();
    }
    path = vector<vector<int>>();
    um.clear();
    memset(in, 0, sizeof(in));
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        rev[b].push_back(a);
      
    }
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= N; ++i) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs1(i);
    }
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    while (!s.empty()) {
        int now = s.top();
        s.pop();
        if (visited[now]) continue;
        visited[now] = 1;
        path.push_back({ now });
        um[now] = cnt;
        dfs2(now, cnt);
        cnt++;
    }
    int ans = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            if (um[graph[i][j]] != um[i]) {
                in[um[graph[i][j]]]++;
            }
        }
    }

    for (int i = 0; i < cnt; ++i) {
        if (in[i] == 0) {
            q.push(i);
            visited[i] = 1;
            ans++;
        }
    }
    cout << ans << "\n";
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T; for (int i = 0; i < T; ++i) solve();
    return 0;
}