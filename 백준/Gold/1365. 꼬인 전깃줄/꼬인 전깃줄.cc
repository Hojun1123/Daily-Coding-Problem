#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N;
int arr[100011];
int dp[100011];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        //
        cin >> arr[i];
    }
    int end = 0;
    dp[0] = -1;
    for (int i = 0; i < N; ++i)
    {
        if (dp[end] < arr[i]) {
            dp[++end] = arr[i];
        }
        else {
            int* ptr = lower_bound(dp, dp + end + 1, arr[i]);
            *ptr = arr[i];
        }
    }
    cout << N - end;
    return 0;
}