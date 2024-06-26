#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, M;
int capacity[401][401];
int flow[401][401];
int networkFlow(int source, int sink)
{
    int result = 0;
    while (true)
    {
        int parent[401];
        queue<int> q;
        memset(parent, -1, sizeof(parent));
        q.push(source);
        parent[source] = source;

        while (!q.empty() && parent[sink] == -1)
        {
            int now = q.front();
            q.pop();
            for (int i = 0; i <= 400; ++i)
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

        int mv = 1987654321;
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
    for (int i = 1; i <= N; ++i) {
        capacity[0][i] = 987654321;
        capacity[i][0] = 987654321;
    }
    int cp;
    for (int i = 1; i <= N; ++i) {
        cin >> cp;
        capacity[i][i + 100] = cp;
        capacity[i + 100][i] = cp;
    }
    for (int i = 1; i <= M; ++i)
    {
        cin >> cp;
        capacity[i + 200][400] = cp;
        capacity[400][i + 200] = cp;
    }
    for (int i = 1; i <= M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            cin >> cp;
            capacity[j + 100][i + 200] = cp;
        }
    }
    cout << networkFlow(0, 400);
    return 0;
}