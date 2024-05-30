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

    int end = 0;
    dp[0] = -1;
    for (int i = 0; i < N; ++i) {
        if (arr[i] > dp[end]) {
            //dp의 마지막 값 보다 현재 값이 더 크면
            dp[++end] = arr[i];
        }
        else {
            int* idx = lower_bound(dp, dp + end, arr[i]);
            *idx = arr[i];
        }
    }
    cout << end;
    return 0;
 }