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
int R, C;
int arr[500][500];
int ans[500][500];
struct yx {
    int y, x;
    bool operator==(yx o) const {
        return y == o.y && x == o.x;
    }
};
yx uf[500][500];
//각 칸 위에 공이 있음
//8방향
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
yx Find(yx nxt) {
    if (nxt == uf[nxt.y][nxt.x]) {
        return nxt;
    }
    yx ret = Find(uf[nxt.y][nxt.x]);
    uf[nxt.y][nxt.x] = ret;
    return ret;
}
void Union(yx a, yx b) {
    yx r1 = Find(a);
    yx r2 = Find(b);
    if (r1 == r2) return;
    uf[r2.y][r2.x] = r1;
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> R >>C;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> arr[i][j];
            uf[i][j] = { i, j };
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            int minY = i;
            int minX = j;
            for (int k = 0; k < 8; ++k) {
                int y = dy[k] + i;
                int x = dx[k] + j;
                if (x < 0 || y < 0 || x >= C || y >= R) continue;
                if (arr[y][x] < arr[minY][minX]) {
                    minY = y;
                    minX = x;
                }
            }
            //cout << minY << ", " << minX << ", " << i << ", " << j << "\n";
            Union({ minY, minX }, { i, j });
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            yx r = Find({ i, j });
            ans[r.y][r.x]++;
        }
    }

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}