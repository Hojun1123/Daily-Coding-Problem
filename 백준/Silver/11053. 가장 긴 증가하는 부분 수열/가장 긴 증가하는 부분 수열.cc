#include <iostream>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    dp[0] = 1;
    int answer = dp[0];
    for (int i = 1; i < N; ++i) {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer;
    return 0;
 }