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
int N, M;
int arr[30][30];
int after[30][30];
int diff[30][30];
struct yx {
    int y, x;
};
int check[30][30];
int check2[30][30];
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
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> after[i][j];
        }
    }

    int diffCnt = 0;
    int cnt = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (check[i][j]) continue;
            int currColor = arr[i][j];
            if (currColor != after[i][j]) diffCnt++;
            check[i][j] = cnt;
            q.push({ i, j });
            while (!q.empty()) {
                yx now = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int y = now.y + dy[k];
                    int x = now.x + dx[k];
                    if (x < 0 || y < 0 || x >= M || y >= N) continue;
                    if (arr[y][x] != currColor) continue;
                    if (check[y][x]) continue;
                    check[y][x] = cnt;
                    q.push({ y, x });
                }
            }
            cnt++;
        }
    }

    cnt = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (check2[i][j]) continue;
            int currColor = after[i][j];
            check2[i][j] = cnt;
            q.push({ i, j });
            while (!q.empty()) {
                yx now = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k) {
                    int y = now.y + dy[k];
                    int x = now.x + dx[k];
                    if (x < 0 || y < 0 || x >= M || y >= N) continue;
                    if (after[y][x] != currColor) continue;
                    if (arr[y][x] != arr[now.y][now.x]) continue;
                    if (check2[y][x]) continue;
                    check2[y][x] = cnt;
                    q.push({ y, x });
                }
            }
            cnt++;
        }
    }
    if (diffCnt > 1) {
        cout << "NO";
    }
    else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (check[i][j] != check2[i][j]) {
                    cout << "NO";
                    return 0;
                }
            }
        }
        cout << "YES";
    }
    return 0;
}