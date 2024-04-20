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
int N, M;
int SY, SX, D;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int A[64][64];
int B[64][64];
int check[4][64][64];
int arr[64][64];
int ans = 0;
struct yx { int y, x; };
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    cin >> SY >> SX >> D;
    string a;
    for (int j = 0; j < N; ++j)
    {
        cin >> a;
        for (int k = 0; k < M; ++k)
        {
            A[j][k] = a[k] - '0';
        }
    }
    for (int j = 0; j < N; ++j)
    {
        cin >> a;
        for (int k = 0; k < M; ++k)
        {
            B[j][k] = a[k] - '0';
        }
    }
    
    int cnt = 0;
    int py = SY;
    int px = SX;
    cnt++;
    arr[py][px] = 1;
    int changeCnt = 1;
    int dir = (D + A[py][px]) % 4;
    while (true)
    {
        int y = dy[dir] + py;
        int x = dx[dir] + px;
        
        /*
        cout << cnt << " : " << y << ", " << x << "\n";
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        */
        //check 계산된 방향, a/b, y, x
        
        if (y < 0 || x < 0 || x >= M || y >= N) break;
        int curr = arr[y][x];
        arr[y][x] = 1;
        if (curr)
        {
            //B
            if (check[dir][y][x] == changeCnt) break;
            check[dir][y][x] = changeCnt;
            dir = (dir + B[y][x]) % 4;
        }
        else
        {
            //A
            dir = (dir + A[y][x]) % 4;
            ans = cnt;
            changeCnt++;
        }
        py = y;
        px = x;
        cnt++;
    }
    cout << ans + 1;
    return 0;
}