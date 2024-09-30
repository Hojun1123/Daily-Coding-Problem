#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N, M;
int arr[1002][1002];
int visited[1002][1002];
struct yx {
    int y, x;
};
queue<yx> q;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (arr[i][j]) continue;
            if (visited[i][j]) continue;
            cnt++;
            q.push({ i, j });
            visited[i][j] = 1;
            while (!q.empty()) {
                yx now = q.front(); q.pop();
                for (int k = 0; k < 4; ++k) {
                    int y = dy[k] + now.y;
                    int x = dx[k] + now.x;
                    if (x < 0) x = M - 1;
                    if (x >= M) x = 0;
                    if (y < 0) y = N - 1;
                    if (y >= N) y = 0;
                    if (arr[y][x]) continue;
                    if (visited[y][x]) continue;
                    visited[y][x] = 1;
                    q.push({ y, x });
                }
            }
        }
    }
    cout << cnt;
    return 0;
}