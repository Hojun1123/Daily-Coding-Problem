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
int R, C;
string arr[50];
struct yx { int y, x; };
int check[50][50];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
queue<yx> water;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >> C;
    queue<yx> q;
    int ey, ex;
    for (int i = 0; i < R; ++i)
    {
        cin >> arr[i];
        for (int j = 0; j < C; ++j)
        {
            if (arr[i][j] == 'S') {
                q.push({ i, j });
                check[i][j] = 2;
            }
            else if (arr[i][j] == 'D') {
                ey = i;
                ex = j;
            }
            else if (arr[i][j] == '*')
            {
                water.push({ i, j });
                check[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int qSize = water.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx wn = water.front();
            water.pop();
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + wn.y;
                int x = dx[k] + wn.x;
                if (x < 0 || y < 0 || x >= C || y >= R) continue;
                if (arr[y][x] == 'D' || arr[y][x] == 'X' || check[y][x]) continue;
                water.push({ y, x });
                check[y][x] = 1;
            }
        }

        qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            if (now.y == ey && now.x == ex) {
                cout << cnt;
                return 0;
            }
            for (int k = 0; k < 4; ++k)
            {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= C || y >= R) continue;
                if (arr[y][x] == 'X' || check[y][x]) continue;
                q.push({ y, x });
                check[y][x] = 2;
            }
        }
        cnt++;
    }

    cout << "KAKTUS";
    return 0;
}
