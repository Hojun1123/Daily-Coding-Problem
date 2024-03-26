#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
using namespace std;
#define MAX 1000000000000000000
struct Node {
    int n;
    long long c;
    bool operator<(Node other) const {
        return c > other.c;
    }
};
int T, N, M;
long long ansSum[200001];
long long ans[200001];
long long ans2[200001];
long long mem[100000][2];
vector<Node> graph[200001];
priority_queue<Node> pq;
void dijkstra(int t)
{
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c >= 0)
            graph[a].push_back({ b, c });
        else {
            if (mem[c * -1 - 1][0] <= MAX)
            {
                graph[a].push_back({ b, mem[c * -1 - 1][0] });
            }
            if (mem[c * -1 - 1][1] <= MAX)
            {
                graph[b].push_back({ a, mem[c * -1 - 1][1] });
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        ans2[i] = ans[i] = MAX + 1;
    }

    pq = priority_queue<Node>();
    pq.push({ 1, 0 });
    ans[1] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > ans[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node next = graph[now.n][i];
            long long nextCost = next.c + ans[now.n];
            if (nextCost >= ans[next.n] || nextCost > MAX) continue;
            pq.push({ next.n, nextCost });
            ans[next.n] = nextCost;
        }
    }
    mem[t][0] = ans[2];
    //cout << ans[2] << " ";

    pq = priority_queue<Node>();
    pq.push({ 2, 0 });
    ans2[2] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > ans2[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node next = graph[now.n][i];
            long long nextCost = next.c + ans2[now.n];
            if (nextCost >= ans2[next.n] || nextCost > MAX) continue;
            pq.push({ next.n, nextCost });
            ans2[next.n] = nextCost;
        }
    }
    mem[t][1] = ans2[1];
    //cout << ans2[1] << " "; cout << "\n";
    for (int i = 1; i <= N; ++i)
    {
        graph[i].clear();
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i)
    {
        dijkstra(i);
    }
    cout << (ans[2] > MAX ? -1 : ans[2]);
    return 0;
}