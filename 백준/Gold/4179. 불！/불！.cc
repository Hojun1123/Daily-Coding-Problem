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
//매 분 마다 한칸씩 또는 수평 or 수직 이동
int N, M;
int arr[1000][1000];
struct yx {
    int y, x;
};
queue<yx> fire;
int SY, SX;
int visited[1000][1000];
int dy[4] = { 1, -1, 0 ,0 };
int dx[4] = { 0, 0, 1, -1 };
queue<yx> q;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    string _;
    for (int i = 0; i < N; ++i) {
        cin >> _;
        for (int j = 0; j < M; ++j) {
            //#, ., J, F
            if (_[j] == '.') continue;
            else if (_[j] == '#') arr[i][j] = 1;
            else if (_[j] == 'J') {
                SY = i;
                SX = j;
            }
            else if (_[j] == 'F') {
                fire.push({ i, j });
                arr[i][j] = 1;
            }
        }
    }

    q.push({ SY, SX });
    visited[SY][SX] = 1;
    int cnt = 1;
    while (!q.empty()) {
        int fSize = fire.size();
        for (int k = 0; k < fSize; ++k) {
            yx f = fire.front();
            fire.pop();
            for (int i = 0; i < 4; ++i) {
                int y = dy[i] + f.y;
                int x = dx[i] + f.x;
                if (y < 0 || x < 0 || y >= N || x >= M) continue;
                if (arr[y][x] == 1) continue;
                fire.push({ y, x });
                arr[y][x] = 1;
            }
        }

        int qSize = q.size();
        for (int k = 0; k < qSize; ++k) {
            yx now = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int y = dy[i] + now.y;
                int x = dx[i] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N) {
                    cout << cnt;
                    return 0;
                }
                if (visited[y][x]) continue;
                if (arr[y][x] == 1) continue;
                visited[y][x] = 1;
                q.push({ y, x });
            }
        }
        cnt++;
    }
    cout << "IMPOSSIBLE";
    return 0;
}