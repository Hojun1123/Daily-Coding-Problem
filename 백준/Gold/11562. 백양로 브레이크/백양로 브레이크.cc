#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N, M, K;
struct Node {
    int n, cnt;
    bool operator<(Node o) const {
        return cnt > o.cnt;
    }
};
vector<Node> graph[251];
priority_queue<Node> pq;
int ans[251][251];
void dijkstra(int s)
{
    for (int i = 1; i <= N; ++i)
    {
        ans[s][i] = 1000000000;
    }
    
    ans[s][s] = 0;
    pq.push({ s, 0 });
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.cnt > ans[s][now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node nxt = graph[now.n][i];
            int nxtCost = ans[s][now.n] + nxt.cnt;
            if (nxtCost >= ans[s][nxt.n]) continue;
            ans[s][nxt.n] = nxtCost;
            pq.push({ nxt.n, nxtCost });
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1) {
            graph[b].push_back({ a, 0 });
        }
        else {
            graph[b].push_back({ a, 1 });
        }
        graph[a].push_back({ b, 0 });
    }
    for (int i = 1; i <= N; ++i) {
        dijkstra(i);
    }
    cin >> K;
    for (int i = 0; i < K; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << ans[a][b] << "\n";
    }
    return 0;
}