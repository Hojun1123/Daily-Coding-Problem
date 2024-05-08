#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
int T, N, M;
int coins[20];
int dp[22222];
void solve()
{
    memset(dp, 0, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> coins[i];
    cin >> M;

    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = coins[i]; j <= M; ++j) {
            //현재 금액에 이전 금액의 경우의 수를 더함.
            dp[j] += dp[j - coins[i]];
        }
    }
    //for (int i = 1; i <= M; ++i) cout << dp[i] << " ";
    cout << dp[M] << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; ++i) solve();
    return 0;
}