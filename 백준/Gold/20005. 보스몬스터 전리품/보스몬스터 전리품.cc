#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
int N, M, P;
string input[1000];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
struct yx {
    int y, x;
};
int dps[155];
int HP;
int result[155];
queue<yx> q;
int visited[1000][1000];
int answer[155];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> P;
    //.길, X이동불가, B보스 위치, a-z 플레이어
    for (int i = 0; i < N; ++i) {
        cin >> input[i];
    }
    char ppp;
    int atk;
    for (int i = 0; i < P; ++i) {
        cin >> ppp;
        cin >> dps[ppp];
    }
    cin >> HP;

    int ff = 0;
    int by, bx;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (input[i][j] == 'B') {
                ff = 1;
                by = i;
                bx = j;
                break;
            }
        }
        if (ff) break;
    }

    for (char i = 'a'; i <= 'z'; ++i) {
        result[i] = 987654321;
    }
    q.push({ by , bx });
    visited[by][bx] = 1;
    int cnt = 0;
    while (!q.empty()) {
        int qSize = q.size();
        for (int i = 0; i < qSize; ++i) {
            yx now = q.front();
            q.pop();
            if (input[now.y][now.x] >= 'a' && input[now.y][now.x] <= 'z') {
                result[input[now.y][now.x]] = cnt;
            }
            for (int k = 0; k < 4; ++k) {
                int y = dy[k] + now.y;
                int x = dx[k] + now.x;
                if (x < 0 || y < 0 || x >= M || y >= N) continue;
                if (visited[y][x]) continue;
                if (input[y][x] == 'X') continue;
                visited[y][x] = 1;
                q.push({ y, x });
            }
        }
        cnt++;
    }

    ////debug
    //for (char i = 'a'; i <= 'z'; ++i) {
    //    cout << i << ": " << result[i] << "\n";
    //}

    //atk
    int tp = 0;
    while (HP > 0) {
        for (int i = 0; i < P; ++i) {
            if (result[i + 'a'] > tp) continue;
            answer[i + 'a'] = 1;
            HP -= dps[i + 'a'];
        }
        tp++;
    }

    int ans = 0;
    for (char i = 'a'; i <= 'z'; ++i) ans += answer[i];
    cout << ans;
    return 0;
}