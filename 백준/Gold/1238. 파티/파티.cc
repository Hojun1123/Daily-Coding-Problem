#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int N, M, X;
struct node {
    int n;
    int cost;

    bool operator<(node o) const
    {
        return cost > o.cost;
    }
};
vector<node> nodes[1001];
int result[1001];
void dijkstra(int s)
{
    priority_queue<node> pq;
    int answer[1001];
    for (int i = 1; i <= N; ++i)
    {
        answer[i] = 987654321;
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
    if (s == X)
    {
        for (int i = 1; i <= N; ++i)
        {
            result[i] += answer[i];
        }
    }
    else
    {
        result[s] += answer[X];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ b, c });
    }
    for (int i = 1; i <= N; ++i)
    {
        dijkstra(i);
    }
    int maxTime = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (result[i] > maxTime)
            maxTime = result[i];
    }
    cout << maxTime;
    return 0;
}