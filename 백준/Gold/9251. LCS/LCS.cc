#include <vector>
#include <cmath>
#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_map>
using namespace std;
string a, b;
int dp[1001][1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    for (int i = 1; i <= a.length(); ++i)
    {
        for (int j = 1; j <= b.length(); ++j)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[a.length()][b.length()];

    return 0;
}