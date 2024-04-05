#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
#include <unordered_set>
#include <cstring>
using namespace std;
int N, M, H;
int arr[33][11];
int check[33][11];
int ans = 9;
bool isAble()
{
    for (int i = 0; i < N; ++i)
    {
        int x = i;
        for (int j = 0; j < H; ++j)
        {
            if (check[j][x] == 1)
            {
                x += 1;
            }
            else if (check[j][x] == 2)
            {
                x -= 1;
            }
        }
        if (x != i)
        {
            return false;
        }
    }
    return true;
}
void bt(int y, int x, int pick)
{
    if (ans <= pick || pick > 3)
    {
        return;
    }
    if (isAble())
    {
        ans = min(ans, pick);
        return;
        //cout << pick << "\n";
        //for (int i = 0; i < H; ++i){ for (int j = 0; j < N; ++j) cout << check[i][j] << " "; cout << "\n"; }
    }
    if (x >= N - 1)
    {
        x = 0;
        y += 1;
    }
    if (y >= H) {

        return;
    }
    for(int i = y; i < H; ++i)
    {
        for (int j = 0; j < N - 1; ++j)
        {
            if (check[i][j] || check[i][j + 1]) continue;
            check[i][j] = 1;
            check[i][j + 1] = 2;
            bt(i, j + 1, pick + 1);
            check[i][j] = 0;
            check[i][j + 1] = 0;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        //a - 1행에 b - 1, b
        check[a - 1][b - 1] = 1;
        check[a - 1][b] = 2;
    }
    bt(0, 0, 0);
    cout << (ans > 5 ? -1 : ans);
    return 0;
}
 