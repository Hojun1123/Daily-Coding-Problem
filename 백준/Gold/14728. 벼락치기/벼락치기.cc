#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N, T;
int t[100]; //걸리는 시간
int score[100]; //얻을 수 있는 점수
int dp[111][10001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T;
    for (int i = 0; i < N; ++i)
    {
        cin >> t[i] >> score[i];
    }


    for (int i = 1; i <= N; ++i)
    {
        int ct = t[i - 1];
        int cs = score[i - 1];
        for (int j = 1; j <= T; ++j)
        {
            if (j < ct) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - ct] + cs, dp[i - 1][j]);
            }
        }
    }
    cout << dp[N][T];
    return 0;
}