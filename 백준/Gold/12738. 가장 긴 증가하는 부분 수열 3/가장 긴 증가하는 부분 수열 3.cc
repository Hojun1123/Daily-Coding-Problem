#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int arr[1000001];
int dp[1000001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    int index = 0;
    dp[0] = -1000000011;
    for (int i = 0; i < N; ++i)
    {
        if (arr[i] > dp[index])
        {
            //현재 값이 맨 위 값보다 크면.
            dp[++index] = arr[i];
        }
        else
        {
            int* ptr = lower_bound(dp, dp + index + 1, arr[i]);
            *ptr = arr[i];
        }
    }
    cout << index;
    return 0;
 }