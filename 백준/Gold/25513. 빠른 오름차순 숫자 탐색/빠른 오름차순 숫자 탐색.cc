#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
int arr[5][5];
int check[5][5];
int r, c;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
struct yx {
    int y, x;
};

int bfs(int nxt)
{
    memset(check, 0, sizeof(check));
    queue<yx> q;
    q.push({ r, c });
    check[r][c] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int k = 0; k < qSize; ++k) {
            yx now = q.front();
            q.pop();
            if (arr[now.y][now.x] == nxt) {
                r = now.y;
                c = now.x;
                return cnt;
            }
            for (int i = 0; i < 4; ++i) {
                int y = now.y + dy[i];
                int x = now.x + dx[i];
                if (x < 0 || y < 0 || x >= 5 || y >= 5) continue;
                if (check[y][x]) continue;
                if (arr[y][x] == -1) continue;
                check[y][x] = 1;
                q.push({ y, x });
            }
        }
        cnt++;
    }
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> arr[i][j];
        }
    }
    cin >> r >> c;
    int ans = 0;
    for (int i = 1; i <= 6; ++i) {
        int r = bfs(i);
        if (r == -1) {
            cout << -1;
            return 0;
        }
        ans += r;
    }
    cout << ans;
    return 0;
}