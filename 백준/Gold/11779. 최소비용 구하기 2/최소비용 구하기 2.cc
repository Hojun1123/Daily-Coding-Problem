#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N, M;
struct Node {
    int n, c;
    bool operator<(Node o) const {
        return c > o.c;
    }
};
vector<Node> graph[1001];
vector<int> path[1001];
int answer[1001];
priority_queue<Node> pq;
void dijkstra()
{
    int s, e;
    cin >> s >> e;
    for (int i = 1; i <= N; ++i) answer[i] = 2100000000;

    answer[s] = 0;
    pq.push({ s, 0 });

    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        if (now.c > answer[now.n])continue;
        for (int i = 0; i < graph[now.n].size(); ++i)
        {
            Node nxt = graph[now.n][i];
            int nxtCost = answer[now.n] + nxt.c;
            if (nxtCost > answer[nxt.n]) continue;
            if (nxtCost == answer[nxt.n]) {
                path[nxt.n].push_back(now.n);
            }
            else {
                path[nxt.n].clear();
                path[nxt.n].push_back(now.n);
                answer[nxt.n] = nxtCost;
                pq.push({ nxt.n, nxtCost });
            }
        }
    }

    cout << answer[e] << "\n";
    stack<int> ans;
    for (int i = e; i != s; i = path[i][0])
    {
        ans.push(i);
    }
    cout << ans.size() + 1<< "\n";
    cout << s << " ";
    while (!ans.empty()) { cout << ans.top() << " "; ans.pop(); }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        //graph[b].push_back({ a, c });
    }
    dijkstra();
    return 0;
}