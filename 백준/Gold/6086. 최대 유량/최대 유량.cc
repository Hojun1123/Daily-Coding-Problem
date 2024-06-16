#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int flow[150][150];
int capacity[150][150];
int N;
int networkFlow(int s, int e)
{
    int maxFlow = 0;
    while (true)
    {
        int parent[150];
        memset(parent, -1, sizeof(parent));
        queue<int> q;

        parent[s] = s;
        q.push(s);
        while (!q.empty())
        {
            int now = q.front();
            q.pop();
            for (int i = 'A'; i <= 'z'; ++i)
            {
                if (capacity[now][i] - flow[now][i] <= 0) continue;
                if (parent[i] == -1)
                {
                    q.push(i);
                    parent[i] = now;
                }
            }
            if (parent[e] != -1) break;
        }
        if (parent[e] == -1) break;

        int aa = 987654321;
        for (int p = e; p != s; p = parent[p])
        {
            aa = min(aa, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for (int p = e; p != s; p = parent[p])
        {
            flow[parent[p]][p] += aa;
            flow[p][parent[p]] -= aa;
        }
        maxFlow += aa;
    }
    return maxFlow;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char a, b;
        int cp;
        cin >> a >> b >> cp;
        capacity[a][b] += cp;
        capacity[b][a] += cp;
    }
    cout << networkFlow('A', 'Z');
    return 0;
}