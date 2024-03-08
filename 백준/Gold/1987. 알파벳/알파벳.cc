#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <set>
using namespace std;
int R, C;
string arr[20];
int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, 1, -1 };
map<char, int> visited;
int answer = 0;
void dfs(int y, int x, int c)
{
    if (answer < c)
    {
        answer = c;
    }

    for (int i = 0; i < 4; ++i)
    {
        int yy = dy[i] + y;
        int xx = dx[i] + x;
        if (xx < 0 || yy < 0 || xx >= C || yy >= R || visited[arr[yy][xx]]) continue;
        visited[arr[yy][xx]] = 1;
        dfs(yy, xx, c + 1);
        visited[arr[yy][xx]] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        cin >> arr[i];
    }
    visited[arr[0][0]] = 1;
    dfs(0, 0, 1);
    cout << answer;
    return 0;
}
