#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int N, M;
struct node {
    int n;
    int cost;

    bool operator<(node o) const
    {
        return cost > o.cost;
    }
};
vector<node> nodes[801];
int result = 0;
int v1, v2;
int answer[801];
void dijkstra(int s)
{
    priority_queue<node> pq;
    for (int i = 1; i <= N; ++i)
    {
        answer[i] = 500000000;
    }
    
    pq.push({ s, 0 });
    answer[s] = 0;
    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        for (int i = 0; i < nodes[now.n].size(); ++i)
        {
            node next = nodes[now.n][i];
            int nextCost = next.cost + answer[now.n];
            if (answer[next.n] <= nextCost) continue;
            answer[next.n] = nextCost;
            pq.push({ next.n, nextCost });
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ b, c });
        nodes[b].push_back({ a, c });
    }
    cin >> v1 >> v2;
    dijkstra(v1);
    int v11 = answer[1];
    int v1n = answer[N];
    dijkstra(v2);
    int v21 = answer[1];
    int v2n = answer[N];
    if (v11 + v2n > v21 + v1n)
    {
        result = v21 + v1n + answer[v1];
    }
    else
    {
        result = v11 + v2n + answer[v1];
    }
    if (result >= 500000000)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }
    return 0;
}