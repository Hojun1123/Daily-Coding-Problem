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
int capacity[222][222];
int flow[222][222];
int cost[222][222];
int check[222];
int answer[222];
int sink = 201;
int source = 0;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        capacity[source][i] = 1;
        capacity[100 + i][sink] = 1;
        for(int j = 1; j <= N; ++j)
        {
            int a;
            cin >> a;
            cost[i][j + 100] = a;
            cost[j + 100][i] = -a;
            capacity[i][j + 100] = 99999999;
        }
    }

    int r = 0;
    int rcost = 0;
    while (true)
    {
        int parent[222];
        memset(parent, -1, sizeof(parent));
        memset(check, 0, sizeof(check));
        int answer[222];
        for (int i = 0; i <= sink; ++i) answer[i] = 987654321;

        queue<int> q;
        answer[source] = 0;
        q.push(source);
        parent[source] = source;
        check[source] = 1;

        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            check[now] = 0;
            for (int i = 0; i <= sink; ++i)
            {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                int nxtCost = cost[now][i] + answer[now];
                if (nxtCost >= answer[i]) continue;
                answer[i] = nxtCost;
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
        for (int i = sink; i != source; i = parent[i])
        {
            //cout << i << " ";
            mv = min(mv, capacity[parent[i]][i] - flow[parent[i]][i]);
        }
        //cout << "\n";
        for (int i = sink; i != source; i = parent[i])
        {
            flow[parent[i]][i] += mv;
            flow[i][parent[i]] -= mv;
            rcost += mv * cost[parent[i]][i];
        }
        r += mv;
    }

    cout << rcost;
    return 0;
}