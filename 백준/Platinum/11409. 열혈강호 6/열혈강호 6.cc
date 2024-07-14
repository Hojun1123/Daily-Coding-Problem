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
int capacity[802][802];
int flow[802][802];
int cost[802][802];
int answer[802];
int parent[802];
int check[802];
int sink = 1;
int source = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 2; i <= N + 1; ++i)
    {
        int pp;
        cin >> pp;
        for (int j = 0; j < pp; ++j)
        {
            int a, b;
            cin >> a >> b;
            capacity[i][N + a + 1] = 1;
            cost[i][N + a + 1] = b;
            cost[N + a + 1][i] = -b;
        }
    }
    for (int i = 2; i <= N + 1; ++i) {
        capacity[0][i] = 1;
    }
    for (int i = N + 2; i <= N + M + 1; ++i) {
        capacity[i][1] = 1;
    }

    int result = 0;
    int costResult = 0;
    while (true)
    {
        memset(parent, -1, sizeof(parent));
        memset(check, 0, sizeof(check));
        for (int i = 0; i <= N + M + 1; ++i) {
            answer[i] = -1987654321;
        }
        queue<int> q;
        q.push(source);
        parent[source] = source;
        check[source] = 1;
        answer[source] = 0;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            check[now] = 0;
            for (int i = 0; i <= N + M + 1; ++i)
            {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                int nextCost = answer[now] + cost[now][i];
                if (nextCost <= answer[i]) continue;
                answer[i] = nextCost;
                parent[i] = now;
                if (check[i] == 0)
                {
                    check[i] = 1;
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
            costResult += mv * cost[parent[i]][i];
        }
        result += mv;
    }
    cout << result << "\n" << costResult;
    return 0;
}