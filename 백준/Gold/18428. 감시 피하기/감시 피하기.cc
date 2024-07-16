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
struct yx {
    int y, x;
};
vector<yx> teacher;
int N;
int arr[6][6];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int flag = 0;
int check()
{
    for (int i = 0; i < teacher.size(); ++i)
    {
        for (int k = 0; k < 4; ++k)
        {
            int y = teacher[i].y;
            int x = teacher[i].x;
            while (true)
            {
                y += dy[k];
                x += dx[k];
                if (x < 0 || y < 0 || x >= N || y >= N) break;
                if (arr[y][x] == 2) break;
                if (arr[y][x] == 1) {
                    return 0;
                }
            }
        }
    }
    return 1;
}
void bt(int sy, int sx, int cnt)
{
    if (flag) return;
    if(cnt == 3){
        flag = check();
    }
    else if (sx == N) {
        bt(sy + 1, 0, cnt);
    }
    else if (sy == N) {
        return;
    }
    else {
        if (arr[sy][sx] == 0) {
            arr[sy][sx] = 2;
            bt(sy, sx + 1, cnt + 1);
            arr[sy][sx] = 0;
        }
        bt(sy, sx + 1, cnt);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            char a;
            cin >> a;
            if (a == 'X') {
                arr[i][j] = 0;
            }
            else if (a == 'T') {
                arr[i][j] = 3;
                teacher.push_back({ i,j });
            }
            else if (a == 'S') {
                arr[i][j] = 1;
            }
            else if (a == 'O') {
                arr[i][j] = 2;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j) {
            bt(i, j, 0);
        }
    }
    cout << (flag ? "YES" : "NO");
    return 0;
}