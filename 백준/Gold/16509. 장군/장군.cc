#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
int arr[10][9];
int check[10][9];
int SY, SX, EY, EX;
int dy[8][3] = {
    {-1, -2, -3},
    {-1, -2, -3},
    {0, -1, -2},
    {0, 1, 2},
    {0, -1, -2},
    {0, 1, 2},
    {1, 2, 3},
    {1, 2, 3},
};
int dx[8][3] = {
    {0, -1, -2},
    {0, 1, 2},
    {-1, -2, -3},
    {-1, -2, -3},
    {1, 2, 3},
    {1, 2, 3},
    {0, -1, -2},
    {0, 1, 2},
};
struct yx {
    int y, x;
};
queue<yx> q;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> SY >> SX >> EY >> EX;
    q.push({ SY, SX });
    check[SY][SX] = 1;
    int c = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i)
        {
            yx now = q.front();
            q.pop();
            if (now.y == EY && now.x == EX) {
                cout << c;
                return 0;
            }
            for (int k = 0; k < 8; ++k)
            {
                int flag = 1;
                int y, x;
                for (int kk = 0; kk < 2; ++kk)
                {
                    y = dy[k][kk] + now.y;
                    x = dx[k][kk] + now.x;
                    if (x < 0 || y < 0 || x >= 9 || y >= 10) {
                        flag = 0;
                        break;
                    }
                    if (y == EY && x == EX) {
                        flag = 0;
                        break;
                    }
                }
                if (flag == 0) continue;
                y = dy[k][2] + now.y;
                x = dx[k][2] + now.x;
                if (y < 0 || x < 0 || x >= 9 || y >= 10) continue;
                if (check[y][x]) continue;
                q.push({ y, x });
                check[y][x] = 1;
            }
        }
        c++;
    }
    cout << -1;
    return 0;
}