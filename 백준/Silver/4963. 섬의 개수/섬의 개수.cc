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
int w, h;
int board[50][50];
int check[50][50];
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dx[8] = { 0, 0, 1, -1, 1, -1, -1, 1 };
struct yx {
    int y, x;
};
void solve()
{
    cin >> w >> h;
    if (w == 0 || h == 0) return;
    int cnt = 0;
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            cin >> board[i][j];
        }
    }

    memset(check, 0, sizeof(check));
    for (int i = 0; i < h; ++i)
    {
        for (int j = 0; j < w; ++j)
        {
            if (check[i][j] || board[i][j] == 0) continue;
            cnt++;
            queue<yx> q;
            q.push({ i, j });
            check[i][j] = 1;
            while (!q.empty())
            {
                yx now = q.front(); q.pop();
                for (int k = 0; k < 8; ++k) {
                    int y = dy[k] + now.y;
                    int x = dx[k] + now.x;
                    if (x < 0 || y < 0 || x >= w || y >= h || check[y][x]) continue;
                    if (board[y][x] == 0) continue;
                    check[y][x] = 1;
                    q.push({ y, x });
                }
            }
        }
    }
    cout << cnt << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true)
    {
        solve();
        if (w == 0 || h == 0) break;;
    }
    return 0;
}