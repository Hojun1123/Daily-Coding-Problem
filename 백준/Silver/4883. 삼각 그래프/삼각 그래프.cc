#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cstring>
using namespace std;
int N;
long long arr[100000][3];
long long dp[100000][3];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (1) {
        cin >> N;
        if (N == 0) break;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < 3; ++j) {
                cin >> arr[i][j];
                dp[i][j] = 1111111111;
            }
        }
        dp[0][0] = 999999999;
        dp[0][1] = arr[0][1];
        dp[0][2] = arr[0][1] + arr[0][2];
        for (int i = 1; i < N; ++i) {
            dp[i][0] = arr[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = arr[i][1] + min(dp[i][0], min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])));
            dp[i][2] = arr[i][2] + min(dp[i][1], min(dp[i - 1][1], dp[i - 1][2]));
        }
        cout << t++ <<". " << dp[N - 1][1] << "\n";
    }
    return 0;
}