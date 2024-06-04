#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
int N, M;
int K;
string arr[1000];
int dp[1001][1001][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
        for (int j = 0; j < M; ++j) {
            //J O I
            if (arr[i][j] == 'J') {
                dp[i + 1][j + 1][0] = dp[i + 1][j][0] + dp[i][j + 1][0] - dp[i][j][0] + 1;
                dp[i + 1][j + 1][1] = dp[i + 1][j][1] + dp[i][j + 1][1] - dp[i][j][1];
                dp[i + 1][j + 1][2] = dp[i + 1][j][2] + dp[i][j + 1][2] - dp[i][j][2];
            }
            else if (arr[i][j] == 'O') {
                dp[i + 1][j + 1][1] = dp[i + 1][j][1] + dp[i][j + 1][1] - dp[i][j][1] + 1;
                dp[i + 1][j + 1][0] = dp[i + 1][j][0] + dp[i][j + 1][0] - dp[i][j][0];
                dp[i + 1][j + 1][2] = dp[i + 1][j][2] + dp[i][j + 1][2] - dp[i][j][2];
            }
            else {
                dp[i + 1][j + 1][2] = dp[i + 1][j][2] + dp[i][j + 1][2] - dp[i][j][2] + 1;
                dp[i + 1][j + 1][1] = dp[i + 1][j][1] + dp[i][j + 1][1] - dp[i][j][1];
                dp[i + 1][j + 1][0] = dp[i + 1][j][0] + dp[i][j + 1][0] - dp[i][j][0];
            }
        }
    }
    for (int i = 0; i < K; ++i)
    {
        int sy, sx, ey, ex;
        cin >> sy >> sx >> ey >> ex;
        int rj = dp[ey][ex][0];
        int ro = dp[ey][ex][1];
        int ri = dp[ey][ex][2];

        rj -= dp[ey][sx - 1][0];
        rj -= dp[sy - 1][ex][0];
        rj += dp[sy - 1][sx - 1][0];

        ro -= dp[ey][sx - 1][1];
        ro -= dp[sy - 1][ex][1];
        ro += dp[sy - 1][sx - 1][1];

        ri -= dp[ey][sx - 1][2];
        ri -= dp[sy - 1][ex][2];
        ri += dp[sy - 1][sx - 1][2];

        cout << rj << " " << ro << " " << ri << "\n";
    }
    return 0;
 }