#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N;
char arr[5][5];
int dp[5][5];
int dp2[5][5];
int dy[3] = { 0, -1 , -2 };
int dx[3] = { -2, -1, 0 };
int op(int a, char pp, int b)
{
    if (pp == '+') {
        return a + b;
    }
    else if (pp == '*') {
        return a * b;
    }
    else if (pp == '-') {
        return a - b;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            dp[i][j] = -987654321;
            dp2[i][j] = 987654321;
        }
    }

    dp2[0][0] = dp[0][0] = arr[0][0] - '0';
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; ++j)
        {
            if (arr[i][j] < '0' || arr[i][j] > '9') continue;
            int curr = arr[i][j] - '0';

            if (j - 2 >= 0) {
                dp[i][j] = max(dp[i][j], op(dp[i][j - 2], arr[i][j - 1], curr));
                dp2[i][j] = min(dp2[i][j], op(dp2[i][j - 2], arr[i][j - 1], curr));
            }
            if (i - 2 >= 0) {
                dp[i][j] = max(dp[i][j], op(dp[i - 2][j], arr[i - 1][j], curr));
                dp2[i][j] = min(dp2[i][j], op(dp2[i - 2][j], arr[i - 1][j], curr));
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                dp[i][j] = max(dp[i][j], op(dp[i - 1][j - 1], arr[i - 1][j], curr));
                dp[i][j] = max(dp[i][j], op(dp[i - 1][j - 1], arr[i][j - 1], curr));
                dp2[i][j] = min(dp2[i][j], op(dp2[i - 1][j - 1], arr[i - 1][j], curr));
                dp2[i][j] = min(dp2[i][j], op(dp2[i - 1][j - 1], arr[i][j - 1], curr));
            }
        }
    }

    //for (int i = 0; i < N; ++i) { for (int j = 0; j < N; ++j) cout << dp2[i][j] << ' '; cout << '\n'; }
    cout << dp[N - 1][N - 1] << ' ' << dp2[N - 1][N - 1];
    return 0;
}