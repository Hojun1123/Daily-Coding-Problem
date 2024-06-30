#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int flow[301][301];
int capacity[301][301];
int N, M;
int networkFlow(int source, int sink)
{
    int result = 0;
    while (true)
    {
        int parent[301];
        memset(parent, -1, sizeof(parent));
        parent[source] = source;
        queue<int> q;
        q.push(source);

        while (!q.empty() && parent[sink] == -1)
        {
            int now = q.front();
            q.pop();
            for (int i = 1; i <= N; ++i)
            {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                if (parent[i] == -1)
                {
                    parent[i] = now;
                    q.push(i);
                }
            }
        }

        if (parent[sink] == -1) break;

        int mv = 987654321;
        for (int i = sink; i != source; i = parent[i]) {
            mv = min(mv, capacity[parent[i]][i] - flow[parent[i]][i]);
        }
        for (int i = sink; i != source; i = parent[i]) {
            flow[parent[i]][i] += mv;
            flow[i][parent[i]] -= mv;
        }
        result += mv;
    }
    return result;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; ++i)
    {
        cin >> a >> b >> c;
        capacity[a][b] += c;
        capacity[b][a] += c;
    }
    cout << networkFlow(1, N);
    return 0;
}