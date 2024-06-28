#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
// 사람수, K개, 음식 개수
int N, M;
long long price[2501];
struct Node {
    int n;
    long long cost;
    long long minPrice;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
struct Line {
    int n;
    long long cost;
};
vector<Line> graph[2501];
long long answer[2501][2501];
priority_queue<Node> pq;
void dijkstra()
{
    for (int i = 1; i <= N; ++i)
    {
        for(int j = 0; j <= 2500; ++j)
            answer[i][j] = 999999987654321;
    }
    pq.push({ 1, 0, price[1] });
    answer[1][price[1]] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.cost > answer[now.n][now.minPrice]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            long long nxtLength = graph[now.n][i].cost;
            int nxt = graph[now.n][i].n;
            
            long long nxtCost = answer[now.n][now.minPrice] + nxtLength * now.minPrice;
            int minPrice = min(price[nxt], now.minPrice);
            if (nxtCost >= answer[nxt][minPrice]) continue;
            answer[nxt][minPrice] = nxtCost;
            pq.push({ nxt, nxtCost, minPrice });
        }
    }

    /*
    for (int i = 1; i <= N; ++i) {
        long long mv = 999999987654321;
        for (int j = 0; j <= 2500; ++j) {
            mv = min(mv, answer[i][j]);
        }
        cout << mv << " ";
    }
    */
    long long ans = 999999987654321;
    for (int j = 0; j <= 2500; ++j) {
        ans = min(ans, answer[N][j]);
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        cin >> price[i];
    }
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c});
        graph[b].push_back({ a, c});
    }
    dijkstra();
    return 0;
}