#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <numeric>
#include <stack>
#include <sstream>
#include <queue>
using namespace std;
int n;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    int dp[1001];
    // 2, 1
    dp[1] = 1;
    dp[2] = 2;
    //3 3
    //4 5
    //5 8
    //6 13
    // 0~5 >
    int a;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }

    cout << dp[n] % 10007;
    return 0;
}