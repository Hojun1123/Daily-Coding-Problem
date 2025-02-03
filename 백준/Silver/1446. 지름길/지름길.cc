#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int N, D;
struct Node {
    int n, cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
vector<Node> graph[10001];
int ans[20001];
priority_queue<Node> pq;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> D;
    // 지름길 개수, 고속도로의 길이 12 10000
    // 시작 도착 지름길의 길이
    int a, b, c;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }
    for (int i = 0; i < 20001; ++i) ans[i] = 99999;
    for (int i = 0; i <= D; ++i) {
        graph[i].push_back({ i + 1, 1 });
    }
    pq.push({ 0, 0 });
    ans[0] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.cost > ans[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i) {
            Node nxt = graph[now.n][i];
            int nxtCost = nxt.cost + ans[now.n];
            if (nxtCost >= ans[nxt.n]) continue;
            ans[nxt.n] = nxtCost;
            pq.push({ nxt.n, nxtCost });
        }
    }
    cout << ans[D];
    return 0;
}