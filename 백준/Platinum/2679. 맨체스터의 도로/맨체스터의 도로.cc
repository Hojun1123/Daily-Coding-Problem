#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int T;
//정점개수, 간선 수, A->B
int N, E, A, B;
int capacity[1001][1001];
int flow[1001][1001];
struct Node {
    int n, c;
    bool operator<(Node o) const {
        return c < o.c;
    }
};
vector<Node> graph[1001];
int networkFlow(int source, int sink)
{
    int result = 0;
    while (true)
    {
        int parent[1001];
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < N; ++i) {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                if (parent[i] == -1) {
                    parent[i] = now;
                    q.push(i);
                }
            }
        }

        if (parent[sink] == -1) break;

        int mv = 1987654321;
        for (int i = sink; i != source; i = parent[i]) {
            mv = min(mv, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for (int i = sink; i != source; i = parent[i]) {
            flow[parent[i]][i] += mv;
            flow[i][parent[i]] -= mv;
        }
        result += mv;
    }
    return result;
}
int visited[1001];
int answer = 0;
void dfs(int nxt, int v) {
    if (nxt == B) {
        answer = max(v, answer);
        return;
    }
    for (int i = 0; i < graph[nxt].size(); ++i) {
        if (visited[graph[nxt][i].n]) continue;
        visited[graph[nxt][i].n] = 1;
        dfs(graph[nxt][i].n, min(v, graph[nxt][i].c));
        visited[graph[nxt][i].n] = 0;
    }
}
void solve() {
    for (int i = 0; i < N; ++i) graph[i].clear();
    answer = 0;
    memset(visited, 0, sizeof(visited));
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));

    cin >> N >> E >> A >> B;
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        capacity[a][b] = c;
        graph[a].push_back({ b, c });
    }
    visited[A] = 1;
    dfs(A, 1987654321);
    cout << (float(networkFlow(A, B)) / answer) << " ";
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(3);
    cout << fixed;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
    return 0;
}