#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
int N;
int arr[100][100];
int check[100][100];
int visited[100][100];
struct yx {
    int y, x;
};
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int ans = 987654321;
void FF(int sy, int sx)
{
    queue<yx> q;
    queue<yx> nq;
    memset(visited, 0, sizeof(visited));
    q.push({ sy, sx });
    nq.push({ sy, sx });
    visited[sy][sx] = 1;
    check[sy][sx] = 1;
    while (!q.empty())
    {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            for(int k = 0; k < 4; ++k)
            { 
                int y = now.y + dy[k];
                int x = now.x + dx[k];
                if (x >= 0 && y >= 0 && x < N && y < N && check[y][x] == 0 && arr[y][x])
                {
                    q.push({ y, x });
                    nq.push({ y, x });
                    visited[y][x] = 1;
                    check[y][x] = 1;
                }
            }
        }
    }

    int cnt = 0;
    while (!nq.empty())
    {
        int qSize = nq.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = nq.front();
            nq.pop();
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= N || y >= N) continue;
                if (visited[y][x]) continue;
                if (check[y][x] > 0)
                {
                    ans = min(ans, cnt);
                    return;
                }
                nq.push({ y, x });
                visited[y][x] = 1;
            }
        }
        cnt++;
    }
}
void solve()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (check[i][j] == 0 && arr[i][j])
            {
                FF(i, j);
            }
        }
    }
    cout << ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}