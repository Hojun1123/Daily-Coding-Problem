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
int book[101];
int person[101];
int cost[222][222];
int capacity[222][222];
int flow[222][222];
int check[222];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int sink = 201;
    int source = 0;
    for (int i = 1; i <= N; ++i) {
        cin >> capacity[i + 100][sink];
    }
    for (int i = 1; i <= M; ++i) {
        cin >> capacity[source][i];
    }
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> cost[i][100 + j];
            cost[100 + j][i] = -cost[i][100 + j];
            capacity[i][100 + j] = 987654321;
        }
    }

    int r = 0;
    int rc = 0;
    while (true)
    {
        int parent[202];
        memset(parent, -1, sizeof(parent));
        int answer[202];
        for (int i = 0; i <= sink; ++i) {
            answer[i] = 987654321;
        }
        int check[202];
        memset(check, 0, sizeof(check));
        answer[source] = 0;
        parent[source] = source;
        queue<int> q;
        q.push(source);
        check[source] = 1;

        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            check[now] = 0;
            for (int i = 0; i <= sink; ++i)
            {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                int nextCost = answer[now] + cost[now][i];
                if (nextCost >= answer[i]) continue;
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

        int mv = 987654321;
        for (int i = sink; i != source; i = parent[i]) {
            mv = min(mv, capacity[parent[i]][i] - flow[parent[i]][i]);
        }
        for (int i = sink; i != source; i = parent[i]) {
            flow[parent[i]][i] += mv;
            flow[i][parent[i]] -= mv;
            rc += mv * cost[parent[i]][i];
        }
        r += mv;
    }
    cout << rc;
    return 0;
}