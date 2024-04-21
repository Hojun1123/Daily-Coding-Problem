#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
using namespace std;
int N, K;
long long answer = 0;
int dp[201][201];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    //0~N
    for (int i = 1; i <= N; ++i)
    {
        dp[1][i] = 1;   //
    }
    for (int j = 1; j <= K; ++j)
    {
        dp[j][1] = j;//001 100 010
    }
    for (int i = 2; i <= K; ++i)
    {
        for (int j = 2; j <= N; ++j)
        {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
        }
    }
    cout << dp[K][N];
    return 0;
}