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
int N, M, T, C;
int answer[501];
struct Node {
    int n, c;
    bool operator<(Node o) const {
        return c > o.c;
    }
};
vector<Node> graph[501];
priority_queue<Node> pq;
int cow[111];
int check[111];
//1 헛간,
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M>> C >> T;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    for (int i = 0; i < C; ++i)
    {
        cin >> cow[i];
    }

    for (int i = 1; i <= N; ++i) answer[i] = 987654321;
    pq.push({ 1, 0 });
    answer[1] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > answer[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node nxt = graph[now.n][i];
            int nextCost = answer[now.n] + nxt.c;
            if (nextCost >= answer[nxt.n]) continue;
            answer[nxt.n] = nextCost;
            pq.push({ nxt.n, nextCost });
        }
    }

    int cnt = 0;
    for (int i = 0; i < C; ++i)
    {
        int cc = cow[i];
        if (answer[cc] <= T)
        {
            check[i + 1] = 1;
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= C; ++i) {
        if (check[i]) cout << i << "\n";
    }
    return 0;
}