#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N, P;
int capacity[401][401]; // 간선 최대 용량
int flow[401][401]; // 현재 사용중인 용량
int networkFlow(int source, int sink)
{
    memset(flow, 0, sizeof(flow));
    int totalFlow = 0;
    while (true)
    {
        vector<int> parent(N + 1, -1);
        queue<int> q;

        parent[source] = source;
        q.push(source);

        // 더 이상 나아갈 수 없거나, 목적지에 도달한 경우
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

        // 증가 경로를 못 찾는다면 종료
        if (parent[sink] == -1) break;

        int amount = 987654321;
        // 역으로 탐색하면서, 유량을 얼마나 보낼지 탐색
        for (int p = sink; p != source; p = parent[p]){
            amount = min(capacity[parent[p]][p] - flow[parent[p]][p], amount);
        }

        // 유량 보내기
        for (int p = sink; p != source; p = parent[p]) {
            flow[parent[p]][p] += amount;
            flow[p][parent[p]] -= amount;
        }

        totalFlow += amount;
    }
    return totalFlow;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> P;
    for (int i = 0; i < P; ++i)
    {
        int a, b;
        cin >> a >> b;
        capacity[a][b] = 1;
    }
    cout << networkFlow(1, 2);
    return 0;
}