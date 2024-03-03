#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
int V, E;
struct node {
    int a;
    int cost;

    bool operator<(node other) const {
        return cost > other.cost;
    }
};
vector<node> nodes[201];
int answer[201];
int result[201][201];
void dijkstra(int s)
{
    vector<int> path[201];
    for (int i = 1; i <= V; ++i)
    {
        answer[i] = 987654321;
    }
    priority_queue<node> pq;
    pq.push({ s, 0 });
    answer[s] = 0;
    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        for (node& nt : nodes[now.a])
        {
            int nextCost = nt.cost + answer[now.a];
            if (nextCost > answer[nt.a])continue;
            else if (nextCost == answer[nt.a])
            {
                path[nt.a].push_back(now.a);
            }
            else
            {
                path[nt.a].clear();
                path[nt.a].push_back(now.a);
                pq.push({ nt.a, nextCost });
                answer[nt.a] = nextCost;
            }
        }
    }

    for (int i = 1; i <= V; ++i)
        result[i][s] = (path[i].size() > 0 ? path[i][0] : - 1);
    
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> V >> E;
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        nodes[a].push_back({ b, c });
        nodes[b].push_back({ a, c });
    }

    for (int i = 1; i <= V; ++i)
    {
        dijkstra(i);
    }

    for (int i = 1; i <= V; ++i)
    {
        for (int j = 1; j <= V; ++j)
        {
            if (result[i][j] == -1)
                cout << "- ";
            else
                cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}