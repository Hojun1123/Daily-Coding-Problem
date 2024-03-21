#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
int N, M, S, D;
struct Node {
    int n, cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
int graph[500][500];
int answer[500];
vector<int> path[500];
priority_queue<Node> pq;
void DeleteNode(int n)
{
    for (int i = 0; i < path[n].size(); ++i)
    {
        int nn = path[n][i];
        if (graph[nn][n] == 0) continue;
        graph[nn][n] = 0;
        DeleteNode(nn);
    }
}
void dijkstra()
{
    for (int i = 0; i < N; ++i)
    {
        answer[i] = 2100000000;
        path[i].clear();
    }
    pq.push({ S, 0 });
    answer[S] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        for (int i = 0; i < N; ++i)
        {
            int nc = graph[now.n][i];
            if (nc == 0) continue;
            int nextCost = nc + answer[now.n];
            if (nextCost > answer[i]) continue;
            if(nextCost == answer[i])
            {
                path[i].push_back(now.n);
            }
            else if (nextCost < answer[i])
            {
                path[i].clear();
                path[i].push_back(now.n);
                pq.push({ i, nextCost });
                answer[i] = nextCost;
            }
        }
    }
    //cout << answer[D] << "\n";
    
    DeleteNode(D);

    for (int i = 0; i < N; ++i)
    {
        answer[i] = 2100000000;
    }
    pq.push({ S, 0 });
    answer[S] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        for (int i = 0; i < N; ++i)
        {
            int nc = graph[now.n][i];
            if (nc == 0) continue;
            int nextCost = nc + answer[now.n];
            if (nextCost >= answer[i]) continue;
            pq.push({ i, nextCost });
            answer[i] = nextCost;
        }
    }
    cout << (answer[D] > 2000000000 ? -1 : answer[D]) << "\n";
}
bool solve()
{
    cin >> N >> M;
    memset(graph, 0, sizeof(graph));
    if (N == 0) return false;
    cin >> S >> D;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }

    dijkstra();

    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (solve()) {}
    return 0;
}