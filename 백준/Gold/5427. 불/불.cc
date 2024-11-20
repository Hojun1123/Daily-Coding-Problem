#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
#pragma warning(disable:4996)
int T, N, M;
string arr[1002];
int check[1002][1002];
struct yx {
    int y, x;
};
queue<yx> q;
queue<yx> sang;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
void solve() {
    sang = queue<yx>();
    q = queue<yx>();
    memset(check, 0, sizeof(check));
    cin >> M >> N;
    for (int i = 1; i <= N; ++i) {
        string a;
        cin >> a;
        arr[i] = "." + a;
        for (int j = 1; j <= M; ++j) {
            if (arr[i][j] == '@') {
                sang.push({ i, j });
                check[i][j] = 2;
            }
            else if (arr[i][j] == '*') {
                q.push({ i, j });
                check[i][j] = 1;
            }
        }
    }
    //for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cout << check[i][j] << " "; cout << "\n"; }
    int ans = 1;
    while (!sang.empty()) {
        int qSize = q.size();
        for (int k = 0; k < qSize; ++k) {
            yx curr = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int y = curr.y + dy[i];
                int x = curr.x + dx[i];
                if (x <= 0 || y <= 0 || x > M || y > N)continue;
                if (check[y][x] == 1) continue;
                if (arr[y][x] == '.') {
                    check[y][x] = 1;
                    q.push({ y, x });
                }
            }
        }
        qSize = sang.size();
        for (int k = 0; k < qSize; ++k) {
            yx curr = sang.front();
            sang.pop();
            if (curr.y == N || curr.x == M || curr.x == 1 || curr.y == 1) {
                cout << ans << "\n";
                return;
            }
            for (int i = 0; i < 4; ++i) {
                int y = curr.y + dy[i];
                int x = curr.x + dx[i];
                if (x <= 0 || y <= 0 || x > M || y > N)continue;
                if (check[y][x]) continue;
                if (arr[y][x] == '.') {
                    check[y][x] = 2;
                    sang.push({ y, x });
                }
            }
        }
        ans++;
    }
    cout << "IMPOSSIBLE\n";
}
int main(int argc, char** argv)
{
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) solve();
    return 0;
}