#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N, M;
int flow[801][801];//400개 마을 -> 1 401 , 2 402.... 400 -> 800
int capacity[801][801];
int networkFlow(int source, int sink)
{
    int result = 0;
    while (true)
    {
        int parent[801];
        memset(parent, -1, sizeof(parent));
        queue<int> q;
        q.push(source);
        parent[source] = source;
        while (!q.empty() && parent[sink] == -1)
        {
            int now = q.front();
            q.pop();
            for (int i = 1; i <= N + 400; ++i)
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
        for (int p = sink; p != source; p = parent[p]){
            mv = min(mv, capacity[parent[p]][p] - flow[parent[p]][p]);
        }
        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += mv;
            flow[p][parent[p]] -= mv;
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
    int a, b;
    for (int i = 0; i < M; ++i) {
        cin >> a >> b;
        capacity[a + 400][b] = 987654300;
        capacity[b + 400][a] = 987654300;
    }
    for (int i = 1; i <= N; ++i) {
        capacity[i][i + 400] = 1;
    }
    cout << networkFlow(401, 2);
    return 0;
}