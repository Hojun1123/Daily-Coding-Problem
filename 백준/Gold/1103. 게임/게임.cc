#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int N, M;
string arr[50];
//이번턴에 다시 돌아왔으면 loop
//
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
int nowVisited[50][50];
int done[50][50];
int loopFlag = 0;
int dfs(int py, int px)
{
    if (loopFlag) return 0;
    if (py < 0 || px < 0 || py >= N || px >= M) {
        return 0;
    }
    if (nowVisited[py][px]) {
        cout << "-1";
        loopFlag = 1;
        return 0;
    }
    if (arr[py][px] == 'H') return 0;
    if (done[py][px] != -1) {
        return done[py][px];
    }
    nowVisited[py][px] = 1;
    int step = arr[py][px] - '0';
    int maxValue = 1;
    for (int k = 0; k < 4; ++k)
    {
        int y = dy[k]*step + py;
        int x = dx[k]*step + px;
        maxValue = max(maxValue, dfs(y, x) + 1);
    }
    done[py][px] = maxValue;
    nowVisited[py][px] = 0;
    return done[py][px];
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
            done[i][j] = -1;
    }

    //H 1 ~9
    int rr = dfs(0, 0);
    if (loopFlag) {
        return 0;
    }
    cout << rr;
    return 0;
}