#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int N;
int arr[1000011];
int dp[1000011];
vector<int> path;
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    dp[0] = -1111111111;//
    int level = 0;
    for (int i = 0; i < N; ++i)
    {
        if (dp[level] < arr[i]) {
            dp[++level] = arr[i];
            path.push_back(level);
        }
        else {
            int* ptr = lower_bound(dp, dp + level + 1, arr[i]);
            *ptr = arr[i];
            int value = ptr - dp;
            path.push_back(value);
        }
    }
    stack<int> ans;
    for (int i = N - 1; i >= 0; --i)
    {
        if (level < 1) break;
        if (path[i] == level) {
            ans.push(arr[i]);
            level--;
        }
    }
    cout << ans.size() << "\n";
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    return 0;
}