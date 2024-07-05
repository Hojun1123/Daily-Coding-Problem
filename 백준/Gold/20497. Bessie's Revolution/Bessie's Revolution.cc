#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N;
string input[15];
int arr[15][15];
int check[12][12];
int visited[12][12];
int answer = 0;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x;
};
int base = 0;
void solve(int sy, int sx)
{
    arr[sy][sx] = 1;
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j]) continue;
            if (arr[i][j]) continue;
            queue<yx> q;
            q.push({ i, j });
            visited[i][j] = 1;
            cnt++;
            while (!q.empty()) {
                yx now = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int y = dy[k] + now.y;
                    int x = dx[k] + now.x;
                    if (x < 0 || y < 0 || x >= N || y >= N) continue;
                    if (arr[y][x]) continue;
                    if (visited[y][x]) continue;
                    visited[y][x] = 1;
                    q.push({ y, x });
                }
            }
        }
    }
    arr[sy][sx] = 0;
    answer += ((cnt > 1 && base < cnt) ? 1 : 0);

    //cout << "\n"; for (int i = 0; i < N; ++i) { for (int j = 0; j < N; ++j) cout << arr[i][j]; cout << "\n"; }
}
void bfs()
{
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (visited[i][j]) continue;
            if (arr[i][j]) continue;
            queue<yx> q;
            q.push({ i, j });
            visited[i][j] = 1;
            base++;
            while (!q.empty()) {
                yx now = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    int y = dy[k] + now.y;
                    int x = dx[k] + now.x;
                    if (x < 0 || y < 0 || x >= N || y >= N) continue;
                    if (arr[y][x]) continue;
                    if (visited[y][x]) continue;
                    visited[y][x] = 1;
                    q.push({ y, x });
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
        for (int j = 0; j < N; ++j) {
            if (input[i][j] == '@' || input[i][j] == 'S') {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
            }
        }
    }
    bfs();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (check[i][j]) continue;
            if (arr[i][j]) continue;
            solve(i, j);
        }
    }
    cout << answer;
    return 0;
}