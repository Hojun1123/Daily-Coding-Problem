#include <vector>
#include <cmath>
#include <iostream>
using namespace std;
int N;
int dp[1000001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    //1, 00
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= N; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    }
    cout << dp[N] % 15746;
}