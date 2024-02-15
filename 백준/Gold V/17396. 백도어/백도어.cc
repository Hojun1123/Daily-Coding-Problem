#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <stack>
using namespace std;
int N, M;
int arr[100000];
struct node {
    int n;
    long long cost;
    bool operator<(node o) const {
        return cost > o.cost;
    }
};
vector<node> graph[100000];
long long answer[100000];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
   
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        answer[i] = 99999999999999;
    }
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a != 0 && a != N - 1 && arr[a]) continue;
        if(b != 0 && b != N -1 && arr[b]) continue;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    
    priority_queue<node> pq;
    pq.push({ 0, arr[0] });
    answer[0] = arr[0];
    while (!pq.empty())
    {
        node now = pq.top();
        pq.pop();
        if (answer[now.n] < now.cost)
            continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            node next = graph[now.n][i];
            long long nextCost = next.cost + answer[now.n];
            if (nextCost >= answer[next.n]) continue;
            answer[next.n] = nextCost;
            pq.push({ next.n, nextCost });
        }
    }
    cout << (answer[N - 1] > 99999999999998 ? -1 : answer[N-1]);
    return 0;
}