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
int capacity[808][808];
int flow[808][808];
int cost[808][808];
//0 source
//1 ~ 400 person
//401 ~ 800 task
// 801 sink
int source = 0;
int sink = 801;
void nt()
{
    int result = 0;
    int costResult = 0;
    while (1)
    {
        int parent[808];
        memset(parent, -1, sizeof(parent));
        int check[808];
        memset(check, 0, sizeof(check));
        int answer[808];
        for (int i = 0; i <= sink; ++i) answer[i] = 1987654321;

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
            for (int i = 0; i <= sink; ++i)
            {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                int nextCost = answer[now] + cost[now][i];
                if (nextCost >= answer[i]) continue;
                answer[i] = nextCost;
                parent[i] = now;
                if (check[i] == 0)
                {
                    q.push(i);
                    check[i] = 1;
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
            //cout << parent[i] << "-" << i << "\n";
            costResult += mv * cost[parent[i]][i];
        }
        result += mv;
    }
    cout << result << "\n" << costResult;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i)
    {
        int cc;
        cin >> cc;
        for (int j = 0; j < cc; ++j) {
            int aa, bb;
            cin >> aa >> bb;
            capacity[i][aa + 400] = 1;
            cost[i][aa + 400] = bb;
            cost[aa + 400][i] = -bb;
        }
    }
    for (int i = 1; i <= N; ++i) {
        capacity[source][i] = 1;
    }
    for (int i = 1; i <= M; ++i) {
        capacity[i + 400][sink] = 1;
    }
    nt();
    return 0;
}