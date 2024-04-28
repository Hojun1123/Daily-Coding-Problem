#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int N, K;
int arr[100][100];
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };
long long ans[100][100][3];
//해당 좌표에 해당 레벨로 접근할 때의 비용.
struct Node {
    int y, x, level;
    long long cost;
    bool operator<(Node o) const {
        return cost > o.cost;
    }
};
priority_queue<Node> pq;
void dijkstra()
{
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < 3; ++k) {
                ans[i][j][k] = 999999987654321;
            }
        }
    }
    ans[0][0][0] = 0;   //시작좌표, 시작 0
    pq.push({ 0, 0, 0, 0 });
    while (!pq.empty()) {
        Node now = pq.top();
        pq.pop();
        if (now.cost > ans[now.y][now.x][now.level]) continue;
        for (int k = 0; k < 4; ++k) {
            int y = dy[k] + now.y;
            int x = dx[k] + now.x;
            if (x < 0 || y < 0 || x >= N || y >= N) continue;
            long long nextCost = ans[now.y][now.x][now.level] + K;
            int nextLevel = now.level + 1;
            if (nextLevel > 2) {
                nextLevel = 0;
                nextCost += arr[y][x];
            }
            if (nextCost >= ans[y][x][nextLevel]) continue;
            ans[y][x][nextLevel] = nextCost;
            pq.push({ y, x, nextLevel, nextCost });
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }
    dijkstra();
    cout << min(ans[N - 1][N - 1][0], min(ans[N - 1][N - 1][1], ans[N - 1][N - 1][2]));
    return 0;
}