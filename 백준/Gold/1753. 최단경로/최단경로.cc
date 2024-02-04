#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include<cstring>
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
vector<node> edge[20001];
int answer[20001];
int V, E, S;
void dijkstra()
{
    for (int i = 1; i <= V; ++i)
    {
        answer[i] = 987654321;
    }
    priority_queue<node> pq;
    pq.push({ S, 0 });
    answer[S] = 0;

    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        for (int i = 0; i < edge[now.n].size(); ++i)
        {
            node next = edge[now.n][i];
            int nextCost = answer[now.n] + next.cost;
            if (answer[next.n] <= nextCost) continue;
            pq.push({ next.n, nextCost });
            answer[next.n] = nextCost;
        }
    }
}
int main()
{
    cin >> V >> E >> S;
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].push_back({ b, c });
    }
    dijkstra();
    for (int i = 1; i <= V; ++i)
    {
        if (answer[i] == 987654321)
            cout << "INF\n";
        else    
            cout << answer[i] << "\n";
    }
    return 0;
}