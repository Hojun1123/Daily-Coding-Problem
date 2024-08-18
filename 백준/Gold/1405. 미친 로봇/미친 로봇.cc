#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
//동서남북
int N;
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
double ff[4];
double ans = 0.0;
int check[200][200];
void bt(int index, int sy, int sx, double sp)
{
    if (index == N) {
        ans += sp;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int y = dy[i] + sy;
        int x = dx[i] + sx;
        double p = ff[i] * sp;
        if (check[y][x]) continue;
        check[y][x] = 1;
        bt(index + 1, y, x, p);
        check[y][x] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(15);
    cout << fixed;
    cin >> N;
    for (int i = 0; i < 4; ++i) {
        int a; cin >> a;
        ff[i] = a / 100.0;
    }
    check[100][100] = 1;
    bt(0, 100, 100, 1.0);
    cout << ans;
    return 0;
}