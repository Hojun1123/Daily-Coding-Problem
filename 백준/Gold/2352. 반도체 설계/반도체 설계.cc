#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
int arr[40011];
int dp[40111];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    dp[0] = -1;
    int index = 0;
    for (int i = 0; i < N; ++i)
    {
        if (dp[index] < arr[i]) {
            dp[++index] = arr[i];
        }
        else {
            int* ptr = lower_bound(dp, dp + index + 1, arr[i]);
            *ptr = arr[i];
        }
    }
    cout << index;
    return 0;
 }