#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, M, K;
struct Node {
    int n;
    long long cost;
    int cnt;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
vector<Node> graph[10001];
long long answer[10001][22];
priority_queue<Node> pq;
vector<int> path[10001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
    for (int i = 1; i <= N; ++i) {
        for(int j = 0; j <= K; ++j) answer[i][j] = 99999987654321;
    }
    pq.push({ 1, 0, 0 });
    answer[1][0] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (answer[now.n][now.cnt] < now.cost) continue;

        for (int i = 0; i < graph[now.n].size(); ++i) {
            Node nxt = graph[now.n][i];
            long long nextCost = now.cost + nxt.cost;
            if (nextCost < answer[nxt.n][now.cnt]) {
                answer[nxt.n][now.cnt] = nextCost;
                pq.push({ nxt.n, nextCost, now.cnt });
            }
            if (now.cnt < K) {
                if (now.cost < answer[nxt.n][now.cnt + 1])
                {
                    answer[nxt.n][now.cnt + 1] = now.cost;
                    pq.push({ nxt.n, now.cost, now.cnt + 1 });
                }
            }
        }
    }
    /*
    for (int i = 0; i <= N; ++i)
    {
        for (int k = 0; k <= K; ++k)
        {
            cout << answer[i][k] << " ";
        }
        cout << "\n";
    }
    */
    long long minValue = 99999987654321;
    for (int i = 0; i <= K; ++i) minValue = min(minValue, answer[N][i]);
    cout << minValue;
    return 0;
}