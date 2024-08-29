#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int T, W;
int arr[1001];
// x 번 이동해서 y초에 잡
int dp[1001][31];
//자두는 허공에서 집어야함
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T >> W;
    for (int i = 1; i <= T; ++i) cin >> arr[i];
    
    // 각 경우는 이동 or 이동 x
    // 이동 횟수가 짝수면 1, 홀수면 0
    for (int i = 1; i <= T; ++i)
    {
        int pos = arr[i];
        for (int j = 0; j <= W; ++j)
        {
            int jadu = (j % 2) + 1;
            if (j != 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
            if (jadu == pos)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
            }
            else
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }

    cout << dp[T][W];
    /*
    for (int i = 1; i <= T; ++i) {
        for (int j = 0; j <= W; ++j) cout << dp[i][j] << " ";
        cout << "\n";
    }
    */
    return 0;
}