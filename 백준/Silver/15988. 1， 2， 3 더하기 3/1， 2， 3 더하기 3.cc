#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;
long long dp[1000011];
int N;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    int maxNum = 0;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        arr.push_back(a);
        maxNum = max(maxNum, a);
    }
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for (int i = 4; i <= maxNum; ++i)
    {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009 ;
    }
    for (int a : arr) {
        cout << dp[a] % 1000000009<< "\n";
    }
    return 0;
}