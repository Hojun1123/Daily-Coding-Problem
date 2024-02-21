#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, X;
struct Node {
    int n, cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
vector<Node> v[1001];
int answer[1001];
void dijkstra()
{
    for (int i = 1; i <= N; ++i)
    {
        answer[i] = 987654321;
    }
    priority_queue<Node> pq;
    pq.push({ X, 0 });
    answer[X] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        for (auto i : v[now.n])
        {
            int nextCost = i.cost + answer[now.n];
            if (nextCost >= answer[i.n]) continue;
            pq.push({ i.n, nextCost });
            answer[i.n] = nextCost;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    //N개의 집과 M개의 길, 마을을 두개로 분할
    //마을은 집이 하나 있어야 함
    // N - 2 개의 경로를 뽑음 됨
    cin >> N >> M >> X;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        v[b].push_back({ a, c });
    }
    dijkstra();
    int r = 0;
    for (int i = 1; i <= N; ++i)
    {
        if (i == N) continue;
        if (r < answer[i])
            r = answer[i];
    }
    cout << r * 2;
    return 0;
}