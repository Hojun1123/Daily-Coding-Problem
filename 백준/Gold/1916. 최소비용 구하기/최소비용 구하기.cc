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
int N, M, S, D;
struct node {
    int d;
    int cost;

    bool operator<(node o) const {
        return cost > o.cost;
    }
};
vector<node> edges[100001];
int answer[1001];
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
        edges[a].push_back({ b, c });
    }
    cin >> S >> D;
    
    priority_queue<node> pq;
    pq.push({ S, 0 });
    for (int i = 1; i <= N; ++i)
    {
        answer[i] = 987654321;
    }
    answer[S] = 0;

    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        if (now.d == D)
        {
            cout << answer[D];
            return 0;
        }
        for (int i = 0; i < edges[now.d].size(); ++i)
        {
            node next = edges[now.d][i];
            int nextCost = next.cost + answer[now.d];
            if (nextCost >= answer[next.d]) continue;
            answer[next.d] = nextCost;
            pq.push({ next.d, nextCost });
        }
    }

    cout << answer[D];
    return 0;
}