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
//N
//입장에 필요한 최소 경험치와 1분마다 얻는 경험치
//특정
int N, T;
int minexp[201];
int getexp[201];
int cost[201][201];
int dp[1001][201];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> T;
    for (int i = 1; i <= N; ++i) {
        cin >> minexp[i] >> getexp[i];
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> cost[i][j];
            cost[j][i] = cost[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= N; ++i) {
        if (minexp[i] == 0) {
            dp[0][i] = 0;
        }
    }
    /*
    for (int i = 0; i <= T; ++i) {
        for (int j = 0; j <= N; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
    */

    for (int i = 1; i <= T; ++i) {
        for (int j = 1; j <= N; ++j) {
            //j번째 사냥터일 때 i초에서의 최대
            if (dp[i - 1][j] != -1) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + getexp[j]);
            }
            
            for (int k = 1; k <= N; ++k) {
                int c = cost[k][j];
                //cout << dp[i - c][k] << ", " << minexp[j] << "\n";
                if (i - c < 0) continue;
                if (dp[i - c][k] < minexp[j]) continue;
                dp[i][j] = max(dp[i][j], dp[i - c][k]);
            }
        }
    }

    /*
    for (int i = 0; i <= T; ++i) {
        for (int j = 0; j <= N; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    */

    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans = max(ans, dp[T][i]);
    }cout << ans;
    return 0;
}