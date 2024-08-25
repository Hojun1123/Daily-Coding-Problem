#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, M, K;
//교차로, 도로, 예산은 10억
struct Node {
    //a ,b , c, t
    // 다음노드, 상한선, 비용
    int n, t;
    long long c;
    long long calCost(long long _p) {
        if (_p <= t) {
            return 0;
        }
        else {
            return c * (_p - t) * (_p - t);
        }
    }
    bool operator< (Node o) const {
        return c > o.c;
    }
};
vector<Node> graph[100001];
priority_queue<Node> pq;
long long answer[100001];
bool dijkstra(long long p)
{
    for (int i = 1; i <= N; ++i) answer[i] = 9999999987654321;
    pq.push({ 1, 0, 0 });
    answer[1] = 0;
    while(!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > answer[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node nxt = graph[now.n][i];
            long long nxtCost = answer[now.n];
            if (nxt.t < p) {
                nxtCost += nxt.c * (p - nxt.t) * (p - nxt.t);
            }
            if (nxtCost >= answer[nxt.n]) continue;
            answer[nxt.n] = nxtCost;
            pq.push({ nxt.n, nxt.t, nxtCost });
        }
    }
    //cout << answer[N] << " ";
    return answer[N] <= K;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        //a-b 비용과, T
        graph[a].push_back({ b, d, c });
        graph[b].push_back({ a, d, c });
    }
    
    int ans = -1;
    int left = 0;
    int right = 100000;
    while (left < right)
    {
        int mid = (left + right) / 2;
        int ret = dijkstra(mid);
        if (ret) {
            left = mid + 1;
            ans = mid;
        }
        else {
            right = mid;
        }
    }
    cout << ans;
    return 0;
}