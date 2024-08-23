#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int N, K, R;
int arr[101][101];
struct yx {
    int y, x;
};
int road[101][101][101][101];
vector<yx> cow;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int ans = 0;
void bfs(int idx)
{
    int check[101][101];
    memset(check, 0, sizeof(check));
    queue<yx> q;
    yx currCow = cow[idx];
    q.push(currCow);
    check[currCow.y][currCow.x] = 1;
    while (!q.empty())
    {
        yx now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int y = dy[i] + now.y;
            int x = dx[i] + now.x;
            if (x < 1 || y < 1 || x > N || y > N) continue;
            if (check[y][x]) continue;
            if (road[now.y][now.x][y][x]) continue;
            q.push({ y, x });
            check[y][x] = 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < cow.size(); ++i)
    {
        if (check[cow[i].y][cow[i].x]) continue;
        cnt++;
    }
    //cout << cnt << " ";
    ans += cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //nn의 격자 소 길
    cin >> N >> K >> R;
    for (int i = 0; i < R; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        road[a][b][c][d] = 1;
        road[c][b][a][d] = 1;
        road[c][d][a][b] = 1;
        road[a][d][c][b] = 1;
    }
    for (int i = 0; i < K; ++i) {
        int a, b;
        cin >> a >> b;
        cow.push_back({ a, b });
    }
    for (int i = 0; i < K; ++i)
    {
        bfs(i);
    }
    cout << ans / 2;
    return 0;
}