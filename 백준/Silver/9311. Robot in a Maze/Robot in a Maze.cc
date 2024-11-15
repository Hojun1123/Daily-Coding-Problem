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
#include <regex>
using namespace std;
int N, M, T;
string arr[15];
int check[15][15];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x;
};
queue<yx> q;    
void solve()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == 'S') {
                q.push({ i, j });
                check[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    while (!q.empty())
    {
        int qs = q.size();
        for (int k = 0; k < qs; ++k) {
            yx now = q.front();
            q.pop();
            if (arr[now.y][now.x] == 'G') {
                cout << "Shortest Path: " << cnt << "\n";
                q = queue<yx>();
                memset(check, 0, sizeof(check));
                return;
            }
            for (int i = 0; i < 4; ++i) {
                int y = dy[i] + now.y;
                int x = dx[i] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N || check[y][x] || arr[y][x] == 'X')
                    continue;
                check[y][x] = 1;
                q.push({ y , x });
            }
        }
        ++cnt;
    }
    cout << "No Exit\n";
    memset(check, 0, sizeof(check));
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) solve();

    return 0;
}