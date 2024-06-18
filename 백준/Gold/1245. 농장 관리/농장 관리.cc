#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N, M;
int arr[100][70];
int check[100][70];
int visited[100][70];
int dy[8] = { 1,-1,0,0, -1, -1, 1, 1 };
int dx[8] = { 0, 0,1,-1, -1, 1, -1, 1 };
struct yx {
    int y, x;
};
int dfs(int sy, int sx)
{
    memset(check, 0, sizeof(check));
    queue<yx> q;
    q.push({ sy, sx });
    visited[sy][sx] = 1;
    check[sy][sx] = 1;
    while (!q.empty())
    {
        yx now = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i)
        {
            int y = dy[i] + now.y;
            int x = dx[i] + now.x;
            if (x < 0 || y < 0 || x >= M || y >= N)continue;
            if (check[y][x]) continue;
            check[y][x] = 1;
            int currHeight = arr[now.y][now.x];
            int nxtHeight = arr[y][x];
            if (currHeight < nxtHeight) return 0;
            if (currHeight == nxtHeight) {
                visited[y][x] = 1;
                q.push({ y, x });
            }
        }
    }
    //cout << sy<< " " << sx << "\n";
    return 1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (visited[i][j]) continue;
            answer += dfs(i, j);
        }
    }
    cout << answer;
    return 0;
}