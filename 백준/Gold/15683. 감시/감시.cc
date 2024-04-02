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
int arr[8][8];
int check[8][8];
struct CCTV {
    int n;
    int y, x;
};
vector<CCTV> v;
vector<CCTV> fix;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int dy3[4] = { 1, 1, -1, -1 };
int dx3[4] = { 1, -1, 1, -1 };
int ans;
void bt(int depth)
{
    if (depth == v.size())
    {
        int s = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) s += (check[i][j] == 0 ? 1 : 0);
        }
        ans = min(ans, s);
        return;
    }
    int n = v[depth].n;
    int temp[8][8];
    memcpy(temp, check, sizeof(temp));
    if (n == 1) {
        for (int k = 0; k < 4; ++k)
        {
            int y = v[depth].y;
            int x = v[depth].x;
            check[y][x] = 1;
            while (true) {
                y += dy[k]; x += dx[k];
                if (x < 0 || y < 0 || x >= M || y >= N || arr[y][x] == 6) break;
                check[y][x] = 1;
            }
            bt(depth + 1);
            memcpy(check, temp, sizeof(temp));
        }
    }
    else if (n == 2) {
        for (int k = 0; k < 2; ++k) {
            for (int j = 2 * k; j < 2 * k + 2; ++j) {
                int y = v[depth].y;
                int x = v[depth].x;
                check[y][x] = 1;
                while (true) {
                    y += dy[j]; x += dx[j];
                    if (x < 0 || y < 0 || x >= M || y >= N || arr[y][x] == 6) break;
                    check[y][x] = 1;
                }
            }
            bt(depth + 1);
            memcpy(check, temp, sizeof(temp));
        }
    }
    else if (n == 3) {
        for (int k = 0; k < 4; k++) {
            int y = v[depth].y;
            int x = v[depth].x;
            check[y][x] = 1;
            while (true) {
                y += dy3[k];
                if (y < 0 || y >= N || arr[y][x] == 6) break;
                check[y][x] = 1;
            }
            y = v[depth].y;
            while (true) {
                x += dx3[k];
                if (x < 0 || x >= M || arr[y][x] == 6) break;
                check[y][x] = 1;
            }
            bt(depth + 1);
            memcpy(check, temp, sizeof(temp));
        }
    }
    else if (n == 4) {
        for (int k = 0; k < 4; ++k)
        {
            for (int j = k; j < k + 3; ++j) {
                int y = v[depth].y;
                int x = v[depth].x;
                check[y][x] = 1;
                while (true) {
                    y += dy[j % 4]; x += dx[j % 4];
                    if (x < 0 || y < 0 || x >= M || y >= N || arr[y][x] == 6) break;
                    check[y][x] = 1;
                }
            }
            bt(depth + 1);
            memcpy(check, temp, sizeof(temp));
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            cin >> arr[i][j];
            if (arr[i][j] >= 1 && arr[i][j] <= 4) {
                v.push_back({ arr[i][j], i, j });
            }
            else if (arr[i][j] == 5) {
                fix.push_back({ arr[i][j], i, j });
            }
            else if (arr[i][j] == 6) check[i][j] = 1;
        }
    }
    for (int i = 0; i < fix.size(); ++i)
    {
        for (int k = 0; k < 4; ++k) {
            int y = fix[i].y;
            int x = fix[i].x;
            check[y][x] = 1;
            while (true) {
                y += dy[k]; x += dx[k];
                if (x < 0 || y < 0 || x >= M || y >= N || arr[y][x] == 6) break;
                check[y][x] = 1;
            }
        }
    }
    ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) ans += (check[i][j] == 0 ? 1 : 0);
    }
    bt(0);
    cout << ans;
    return 0;
}
 