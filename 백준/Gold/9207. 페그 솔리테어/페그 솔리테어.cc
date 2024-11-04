#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
string ip[5];
int arr[5][9];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int ans = 0;
int ansdepth = 0;
void bt(int sy, int sx, int depth, int cnt) {
    /*cout << "\n\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 9; ++j)cout << arr[i][j] << " ";
        cout << "\n";
    }
    */

    if (sy == 5) {
        if (ans == cnt) {
            ansdepth = min(ansdepth, depth);
        }
        else if (ans > cnt) {
            ans = cnt;
            ansdepth = depth;
        }
        return;
    }
    if (sx == 9) {
        bt(sy + 1, 0, depth, cnt);
        return;
    }
    if (arr[sy][sx] == -1 || arr[sy][sx] == 0) {
        bt(sy, sx + 1, depth, cnt);
        return;
    }
    bt(sy, sx + 1, depth, cnt);
    for (int i = 0; i < 4; ++i) {
        int y = dy[i] + sy;
        int x = dx[i] + sx;
        if (x < 0 || y < 0 || x >= 9 || y >= 5) continue;
        if (arr[y][x] != 1) continue;
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        if (xx < 0 || yy < 0 || xx >= 9 || yy >= 5) continue;
        if (arr[yy][xx] != 0) continue;
        arr[yy][xx] = 1;
        arr[y][x] = 0;
        arr[sy][sx] = 0;
        bt(0, 0, depth + 1, cnt - 1);
        arr[yy][xx] = 0;
        arr[y][x] = 1;
        arr[sy][sx] = 1;
    }

}
void solve()
{
    //.빈칸, o핀,#구멍x
    ans = 0;
    ansdepth = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> ip[i];
        for (int j = 0; j < 9; ++j) {
            if (ip[i][j] == '#') {
                arr[i][j] = -1;
            }
            else if (ip[i][j] == 'o') {
                arr[i][j] = 1;
                ans++;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    bt(0, 0, 0, ans);
    cout << ans << " " << ansdepth << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        solve();
    }
    return 0;
}