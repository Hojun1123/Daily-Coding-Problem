#include <vector>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <queue>
#include <iostream>
using namespace std;
int M, N;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
string arr[100];
int check[100][100];
int b= 0, w = 0;
struct yx {
    int y, x;
};
queue<yx> q;
void bfs(int n) {
    int cnt = 0;
    char v = ((n == 1) ? 'W' : 'B');
    while (!q.empty()) {
        yx now = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int y = now.y + dy[i];
            int x = now.x + dx[i];
            if (x < 0 || y < 0 || x >= M || y >= N) continue;
            if (check[y][x]) continue;
            if (arr[y][x] == v) {
                check[y][x] = 1;
                q.push({ y, x });
            }
        }
    }
    if (n == 1) w += cnt * cnt;
    else b += cnt * cnt;
}
int main(int argc, char** argv)
{
    cin >> M >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (check[i][j]) continue;
            q.push({ i, j });
            check[i][j] = 1;
            if (arr[i][j] == 'W') {
                bfs(1);
            }
            else {
                bfs(2);
            }
        }
    }
    cout << w << " " << b;
    return 0;
}