#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <string>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    //가장 높은 학생의 점수와 낮은 학생의 점수의 차이의 합
    //s[i]까지의 최대값
    for (int i = 0; i < N; ++i) {
        int maxValue = arr[i];
        int minValue = arr[i];
        for (int j = i - 1; j >= 0; --j) {
            maxValue = max(maxValue, arr[j]);
            minValue = min(minValue, arr[j]);
            dp[i + 1] = max(dp[i + 1], dp[j] + maxValue - minValue);
        }
    }
    //0 3 5 9(6+3) 9(6+3) 10(6+1+3) 14 14 17 20
    //for (int i = 0; i <= N; ++i) cout << dp[i] << " ";
    cout << dp[N];
    return 0;
}