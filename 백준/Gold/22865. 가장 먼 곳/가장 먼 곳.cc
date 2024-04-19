#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, M;
int input[3];
struct Node {
    int n;
    long long cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
long long answer[100001];
long long result[100001];   //가장 최단.
vector<Node> v[100001];
priority_queue<Node> pq;
void dijkstra(int k)
{
    for (int i = 1; i <= N; ++i) answer[i] = 20000000000000;
    pq = priority_queue<Node>();

    pq.push({input[k], 0});
    answer[input[k]] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.cost > answer[now.n]) continue;
        for (int i = 0; i < v[now.n].size(); ++i)
        {
            Node next = v[now.n][i];
            long long nextCost = next.cost + answer[now.n];
            if (nextCost >= answer[next.n]) continue;
            answer[next.n] = nextCost;
            pq.push({ next.n, nextCost });
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        //cout << answer[i] << " ";
        if (answer[i] >= 20000000000000) continue;
        result[i] = min(result[i], answer[i]);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    cin >> input[0] >> input[1] >> input[2];
    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    for (int i = 1; i <= N; ++i) result[i] = 20000000000000;
    for (int i = 0; i < 3; ++i)
    {
        dijkstra(i);
    }
    long long c = 0;
    int rr = 0;
    for (int i = 1; i <= N; ++i) {
        //cout << result[i] << "\n";
        if (result[i] > c) {
            c = result[i];
            rr = i;
        }
    }
    cout << rr;
    return 0;
}