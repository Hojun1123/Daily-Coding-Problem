#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <set>
using namespace std;
int N;
// x, y, d, g
int board[101][101];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
//int change[4] = {3, 0, 1, 2}
stack<int> dir;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int t = 0; t < N; ++t)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        board[y][x] = 1;
        y = dy[d] + y;
        x = dx[d] + x;
        board[y][x] = 1;
        vector<int> tmp;
        tmp.push_back(d);
        for (int i = 0; i < g; ++i)
        {
            //cout << "_\n";
            for (int k = 0; k < tmp.size(); ++k) dir.push(tmp[k]);
            while (!dir.empty())
            {
                int now = (dir.top() + 1) % 4;
                dir.pop();
                y = dy[now] + y;
                x = dx[now] + x;
                tmp.push_back(now);
                board[y][x] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100; ++i)
    {
        for (int j = 1; j <= 100; ++j)
        {
            if (board[i][j] && board[i][j - 1] && board[i - 1][j] && board[i - 1][j - 1])
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}