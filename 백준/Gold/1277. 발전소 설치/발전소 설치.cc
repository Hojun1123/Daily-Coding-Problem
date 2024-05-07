#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
int N, W;
double M;
struct xy {
    long double x, y;
};
struct Node {
    int n;
    long double cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
xy bal[1001];
priority_queue<Node> pq;
long double answer[1001];
vector<Node> graph[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> W >> M;
    for (int i = 1; i <= N; ++i) {
        answer[i] = 1000000000000;
    }
    for (int i = 1; i <= N; ++i) cin >> bal[i].x >> bal[i].y;
    for (int i = 0; i < W; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back({ b, 0 });
        graph[b].push_back({ a, 0 });
    }
    for (int i = 1; i <= N - 1; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            long long distance2 = (bal[i].x - bal[j].x) * (bal[i].x - bal[j].x)
                + (bal[i].y - bal[j].y) * (bal[i].y - bal[j].y);
            if (distance2 > M * M) continue;
            long double dis = sqrt(distance2);
            graph[i].push_back({ j, dis });
            graph[j].push_back({ i, dis });
        }
    }
    pq.push({ 1, 0 });
    answer[1] = 0;
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        if (now.cost > answer[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i) {
            Node nxt = graph[now.n][i];
            long double nextCost = nxt.cost + answer[now.n];
            if (nextCost >= answer[nxt.n]) continue;
            answer[nxt.n] = nextCost;
            pq.push({ nxt.n, nextCost });
        }
    }
    cout << fixed << int(floor(answer[N] * 1000));

    return 0;
}