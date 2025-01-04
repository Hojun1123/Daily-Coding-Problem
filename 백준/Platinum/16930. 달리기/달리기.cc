#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, M, K;
int dy[4] = { 1, -1, 0 ,0 };
int dx[4] = { 0, 0, 1, -1 };
bool arr[1000][1000];
int check[1000][1000];
// K는 1000이하.
// NxM 체육관을 달림. 칸은 빈칸 or 벽
struct yx {
    int y, x;
};
int sx, sy, ex, ey;
queue<yx> q;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        string a;
        cin >> a;
        for (int j = 0; j < M; ++j) {
            if (a[j] == '#') {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    cin >> sy >> sx >> ey >> ex;
    sx--; sy--; ex--; ey--;
    q.push({ sy, sx });
    check[sy][sx] = 1;
    int cnt = 2;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            yx now = q.front();
            q.pop();
            if (now.y == ey && now.x == ex) {
                cout << cnt - 2;
                return 0;
            }
            for (int k = 0; k < 4; ++k) {
                int y = now.y;
                int x = now.x;
                int step = 0;
                while (step < K) {
                    step++;
                    y += dy[k];
                    x += dx[k];
                    if (x < 0 || y < 0 || x >= M || y >= N) break;
                    if (arr[y][x]) break;
                    if (check[y][x] == 0) {
                        check[y][x] = cnt;
                        q.push({ y, x });
                    }
                    else if (check[y][x] == cnt) continue;
                    else if (check[y][x] < cnt) break;
                }
                
            }
        }
        cnt++;
    }
    cout << -1;
    return 0;
}