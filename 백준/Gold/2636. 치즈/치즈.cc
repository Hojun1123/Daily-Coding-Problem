#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int N, M;
int arr[100][100];
struct yx {
    int y, x;
};
int check[100][100];
int result[100][100];
queue<yx> q;
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; ++i){
        q.push({ i, 0 });
        q.push({ i, M - 1 });
    }
    for (int j = 1; j < M - 1; ++j) {
        q.push({ 0, j });
        q.push({ N - 1, j });
    }

    int rr = 0;
    int cnt = 0;
    while (!q.empty())
    {
        memset(result, 0, sizeof(result));
        while (!q.empty()) {
            yx now = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int y = dy[i] + now.y;
                int x = dx[i] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N || check[y][x]) continue;
                if (arr[y][x]) {
                    result[y][x] = 1;
                    continue;
                }
                check[y][x] = 1;
                q.push({ y,x });
            }
        }

        int scnt = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (result[i][j]) {
                    arr[i][j] = 0;
                    check[i][j] = 1;
                    q.push({ i, j });
                    scnt++;
                }
            }
        }
        if (scnt <= 0) break;
        rr = scnt;
        cnt++;
    }
    cout << cnt << "\n" << rr;
}