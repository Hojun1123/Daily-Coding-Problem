#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
struct node {
    int n;
    int cost;
    bool operator<(node other) const {
        if (cost < other.cost) return false;
        else if (cost > other.cost) return true;
        return false;
    }
};
vector<node> edges[50001];
int answer[50001];
int N, M;
void dijkstra()
{
    for (int i = 1; i <= N; ++i)
    {
        answer[i] = 987654321;
    }
    priority_queue<node> pq;
    pq.push({ 1, 0 });
    answer[1] = 0;
    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        for (int i = 0; i < edges[now.n].size(); ++i)
        {
            node next = edges[now.n][i];
            int nextCost = next.cost + answer[now.n];
            if (nextCost >= answer[next.n]) continue;
            pq.push({ next.n, nextCost });
            answer[next.n] = nextCost;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //n 은 1 ~50000
    //m 은 50000갸
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }
    
    dijkstra();
    cout << answer[N];
    return 0;
}