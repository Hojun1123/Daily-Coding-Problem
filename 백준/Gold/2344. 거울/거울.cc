#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
using namespace std;
int N, M;
int arr[1002][1002];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
struct yx {
    int y, x;
    bool operator<(yx o) const {
        if (y < o.y) return true;
        else if (y > o.y) return false;
        return x < o.x;
    }
};
map<yx, int> m;
vector<yx> ans;
void f(int sy, int sx, int sd)
{
    int y = sy + dy[sd];
    int x = sx + dx[sd];
    int d = sd;
    while (true)
    {
        if (x == 0 || y == 0 || x == M + 1 || y == N + 1) {
            ans.push_back({ y, x });
            return;
        }
        if (arr[y][x]) {
            if (d == 0) d = 1;
            else if (d == 1) d = 0;
            else if (d == 2) d = 3;
            else d = 2;
        }
        y += dy[d];
        x += dx[d];
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> arr[i][j];
        }
    }
    int num = 1;
    for (int i = 1; i <= N; ++i) {
        f(i, 0, 1);
        m[{i, 0}] = num++;
    }
    for (int j = 1; j <= M; ++j) {
        f(N + 1, j, 0);
        m[{N + 1, j}] = num++;
    }
    for (int i = N; i > 0; --i) {
        f(i, M + 1, 3);
        m[{i, M + 1}] = num++;
    }
    for (int j = M; j > 0; --j) {
        f(0, j, 2);
        m[{0, j}] = num++;
    }

    for (auto i : ans) cout << m[i] << " ";
    return 0;
}