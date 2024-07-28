#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
//교차로 도로 목적지 후보
// 출발지, g-h
int T, n, m, t, s, g, h;
struct Node {
    int n, c;
    bool operator<(Node o)const {
        return c > o.c;
    }
};
vector<Node> graph[2001];
int ss[2001];   // S - 다른 지점들
int hh[2001];   // H - 다른 지점들
int gg[2001];   // G - 다른 지점들

void dijkstra(int start, int* arr)
{
    priority_queue<Node> pq;
    pq.push({ start, 0 });
    arr[start] = 0;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > arr[now.n]) continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node nxt = graph[now.n][i];
            int nxtCost = nxt.c + arr[now.n];
            if (nxtCost >= arr[nxt.n]) continue;
            arr[nxt.n] = nxtCost;
            pq.push({ nxt.n, nxtCost });
        }
    }
}
void solve()
{
    cin >> n >> m >> t >> s >> g >> h;

    //최단거리 s - t
    for (int i = 1; i <= n; ++i) {
        ss[i] = 1987654321;
        hh[i] = 1987654321;
        gg[i] = 1987654321;
        graph[i].clear();
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    vector<int> des;
    for (int i = 0; i < t; ++i) {
        int a;
        cin >> a;
        des.push_back(a);
    }

    dijkstra(s, ss);
    dijkstra(g, gg);
    dijkstra(h, hh);

    vector<int> result;
    for (int i = 0; i < des.size(); ++i)
    {
        int ret = des[i];
        if (ss[ret] == (ss[g] + gg[h] + hh[ret])
            || ss[ret] == (ss[h] + hh[g] + gg[ret]))
        {
            result.push_back(ret);
        }
    }

    sort(result.begin(), result.end());

    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) solve();
    return 0;
}