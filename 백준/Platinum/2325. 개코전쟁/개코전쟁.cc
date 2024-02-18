#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <vector>
#include <cmath>
#include <sstream>
#include <cctype>
using namespace std;
int N, M;
struct node {
    int n, cost;
    bool operator<(node o) const {
        return cost > o.cost;
    }
};
struct c {
    int a, b, c;
};
vector<node> graph[1001];
int answer[1001];
int maxCost = 0;
vector<int> path[1001];
void d()
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
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            node next = graph[now.n][i];
            int nextCost = next.cost + answer[now.n];
            if (nextCost > answer[next.n]) continue;
            else if (nextCost == answer[next.n])
            {
                path[next.n].push_back(now.n);
            }
            else
            {
                //간선추적
                path[next.n].clear();
                path[next.n].push_back(now.n);
                pq.push({ next.n, nextCost });
                answer[next.n] = nextCost;
            }
        }
    }
}

int check[1001];
vector<c> cases;
queue<int> q;
void bfs()
{
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        if (check[now]) continue;
        check[now] = 1;
        for (int i = 0; i < path[now].size(); ++i)
        {
            int prev = path[now][i];
            q.push(prev);
            cases.push_back({ now, prev, answer[now] - answer[prev] });
        }
    }
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }

    // 다익스트라
    d();

    // bfs, 최단경로 추적
    q.push(N);
    while (!q.empty())
    {
        bfs();
    }

    // 최단경로의 간선 중 하나를 삭제하고 다익스트라 돌리기, 최대값 찾기
    for (c i : cases)
    {
        int j, k;
        for (j = 0; j < graph[i.a].size(); ++j)
        {
            if (graph[i.a][j].n == i.b)
            {
                graph[i.a][j].cost = 10000000;
                break;
            }
        }
        for (k = 0; k < graph[i.b].size(); ++k)
        {
            if (graph[i.b][k].n == i.a)
            {
                graph[i.b][k].cost = 10000000;
                break;
            }
        }
        d();
        if (maxCost < answer[N])
            maxCost = answer[N];
        graph[i.a][j].cost = i.c;
        graph[i.b][k].cost = i.c;
    }
    cout << maxCost;
    return 0;
}