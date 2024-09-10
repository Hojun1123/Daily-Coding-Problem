#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
int N, M;
string arr[500];
int check[500][500];
int visited[500][500];
int dfs(int sy, int sx)
{
    visited[sy][sx] = 1;
    int y = sy;
    int x = sx;
    if (arr[sy][sx] == 'U') {
        y--;
    }
    else if (arr[sy][sx] == 'D') {
        y++;
    }
    else if (arr[sy][sx] == 'R') {
        x++;
    }
    else {
        x--;
    }

    if (x < 0 || x >= M || y < 0 || y >= N) {
        check[sy][sx] = 2;
        return 2;
    }

    if (check[y][x]) {
        check[sy][sx] = check[y][x];
        return check[y][x];
    }
    else if (visited[y][x]) {
        check[sy][sx] = 1;
        return 1;
    }
    check[sy][sx] = dfs(y, x);
    return check[sy][sx];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (check[i][j])continue;
            check[i][j] = dfs(i, j);
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            if (check[i][j] == 2) cnt++;
            //cout << check[i][j] << " ";
        //cout << "\n";
    }
    cout << cnt;
    return 0;
}