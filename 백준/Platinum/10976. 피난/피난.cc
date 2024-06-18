#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, M;
int capacity[201][201];
int flow[201][201];
int networkFlow(int source, int sink)
{
    int result = 0;
    while (true)
    {
        int parent[201];
        queue<int> q;
        memset(parent, -1, sizeof(parent));
        q.push(source);
        parent[source] = source;
        while (!q.empty() && parent[sink] == -1)
        {
            int now = q.front();
            q.pop();
            for (int i = 1; i <= N; ++i)
            {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                if (parent[i] == -1)
                {
                    q.push(i);
                    parent[i] = now;
                }
            }
        }

        if (parent[sink] == -1) break;
        
        int mv = 987654321;
        for (int i = sink; i != source; i = parent[i])
        {
            mv = min(mv, capacity[parent[i]][i] - flow[parent[i]][i]);
        }

        for (int i = sink; i != source; i = parent[i])
        {
            flow[parent[i]][i] += mv;
            flow[i][parent[i]] -= mv;
        }

        result += mv;
    }
    return result;
}
void solve()
{
    cin >> N >> M;
    memset(capacity, 0, sizeof(capacity));
    memset(flow, 0, sizeof(flow));
    int a, b;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b;
        if (a == 1 || b == N)
            capacity[a][b] = 1;
        else
            capacity[a][b] = 987654300;
    }
    cout << networkFlow(1, N) << "\n";
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