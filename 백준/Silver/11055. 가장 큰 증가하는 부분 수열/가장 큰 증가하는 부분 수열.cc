#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <bitset>
#include <stack>
using namespace std;
int dp[1001];
int arr[1001];
int N;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    int ans = arr[0];
    dp[0] = arr[0];
    for (int i = 1; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[j] + arr[i], dp[i]);
                if (ans < dp[i]) ans = dp[i];
            }
        }
    }
    cout << ans;
    return 0;
}