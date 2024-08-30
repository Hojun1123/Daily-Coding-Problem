#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, M, T;
int arr[22];//1 ~ 10000
int dp[10001];
void solve()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
    cin >> M;
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < N; ++i)
    {
        int curr = arr[i];
        for (int j = curr; j <= M; ++j)
        {
            dp[j] = dp[j] + dp[j - curr];
        }
    }
    cout << dp[M] << " ";
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