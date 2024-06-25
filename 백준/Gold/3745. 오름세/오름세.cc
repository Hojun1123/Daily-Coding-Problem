#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
using namespace std;
int N;
int arr[100001];
int dp[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> N)
    {
        for (int i = 0; i < N; ++i)
        {
            cin >> arr[i];
        }

        int end = 0;
        dp[end] = -1;
        for (int i = 0; i < N; ++i)
        {
            if (arr[i] > dp[end])
            {
                dp[++end] = arr[i];
            }
            else
            {
                int* ptr = lower_bound(dp, dp + end + 1, arr[i]);
                *ptr = arr[i];
            }
        }

        cout << end << "\n";
    }
    return 0;
}