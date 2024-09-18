#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, M;
string arr[200];
int visited[200][200];
struct yx {
    int y, x;
};
int dy[3] = { 1, 0, 0 };
int dx[3] = { 0, -1, 1 };
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (true) {
        cin >> N >> M;
        if (N == 0) break;
        memset(visited, 0, sizeof(visited));
        queue<yx> q;
        for (int i = 0; i < N; ++i) cin >> arr[i];

        for (int i = 0; i < N; ++i) {
            for (int j = 1; j < M; ++j) {
                if (arr[i][j] == 'B' && arr[i][j - 1] == 'S') {
                    arr[i][j] = 'S';
                    break;
                }
            }
        }

        for (int j = 1; j < M - 1; ++j) {
            if (arr[0][j] == 'S') {
                q.push({ 0, j });
                visited[0][j] = 1;
            }
        }

        int cnt = 0;
        int flag = 0;
        while (!q.empty()) {
            int qSize = q.size();
            for (int i = 0; i < qSize; ++i) {
                yx now = q.front();
                q.pop();
                if (now.y == N - 1 && arr[now.y][now.x] == 'S') {
                    if (now.x != 0 && now.x != M - 1) {
                        flag = 1;
                        break;
                    }
                }
                for (int k = 0; k < 3; ++k) {
                    int y = dy[k] + now.y;
                    int x = dx[k] + now.x;
                    if (x < 0 || x >= M || y >= N) continue;
                    if (visited[y][x]) continue;
                    if (arr[y][x] != 'S') continue;
                    q.push({ y, x });
                    visited[y][x] = cnt;
                }
            }
            cnt++;
            if (flag) break;
        }

        //for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cout << visited[i][j] << " "; cout << "\n"; }
        cout << cnt << "\n";
    }
    return 0;
}