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
int N, V, E, A, B;
int tps[100];
int S;
struct node {
    int d;
    int cost;

    bool operator<(node o) const {
        if (cost < o.cost) return false;
        else if (cost > o.cost) return true;
        return false;
    }
};
vector<node> edges[1001];
int answer[1001];
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
        for (int i = 0; i < edges[now.d].size(); ++i)
        {
            node next = edges[now.d][i];
            int nextCost = next.cost + answer[now.d];
            if (nextCost >= answer[next.d]) continue;
            pq.push({ next.d, nextCost });
            answer[next.d] = nextCost;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> V >> E;
    cin >> A >> B; //KIST 위치, 씨알푸드 위치
    for (int i = 0; i < N; ++i)
    {
        cin >> tps[i];  //팀원의 위치
    }
    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({ b, c });
        edges[b].push_back({ a, c });
    }
    int result = 0;
    for (int i = 0; i < N; ++i)
    {
        S = tps[i];
        dijkstra();
        result += answer[A] + answer[B];
    }
    cout << result;
    return 0;
}