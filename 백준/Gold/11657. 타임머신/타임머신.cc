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
struct Node {
    int n, cost;
};
vector<Node> graph[501];
queue<int> q;
int check[501];
long long answer[501];
int visitedCnt[501];
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
        graph[a].push_back({ b, c });
    }
    for (int i = 1; i <= N; ++i) answer[i] = 1987654321;
    q.push(1);
    check[1] = 1;
    answer[1] = 0;
    int cnt = 0;
    while (!q.empty())
    {
        //for (int i = 1; i <= N; ++i) cout << answer[i] << " "; cout << "\n";
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            int now = q.front();
            q.pop();
            check[now] = 0;
            visitedCnt[now] ++;
            if (visitedCnt[now] >= N) {
                // 해당 정점을 N 번 이상 방문하였다면.
                cout << -1;
                return 0;
            }

            for (int j = 0; j < graph[now].size(); ++j)
            {
                Node nxt = graph[now][j];
                long long nextCost = answer[now] + nxt.cost;
                if (nextCost >= answer[nxt.n]) continue;
                answer[nxt.n] = nextCost;
                if (check[nxt.n] == 0) {
                    check[nxt.n] = 1;
                    q.push(nxt.n);
                }
            }
        }
    }

    for (int i = 2; i <= N; ++i)
        cout << (answer[i] > 1987654000 ? -1 : answer[i]) << "\n";
    return 0;
}