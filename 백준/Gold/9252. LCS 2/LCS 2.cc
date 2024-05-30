#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
using namespace std;
string a, b;
int dp[1001][1001];
stack<char> path;
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> a >> b;
    for (int i = 0; i < a.size(); ++i)
    {
        for (int j = 0; j < b.size(); ++j)
        {
            if (a[i] == b[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    cout << dp[a.size()][b.size()];
    if (dp[a.size()][b.size()] <= 0) return 0;
    cout << "\n";
    int aIndex = a.size() - 1;
    int bIndex = b.size() - 1;
    while (aIndex >= 0 && bIndex >= 0)
    {
        if (a[aIndex] == b[bIndex])
        {
            path.push(a[aIndex]);
            aIndex--;
            bIndex--;
        }
        else if (dp[aIndex + 1][bIndex + 1] == dp[aIndex][bIndex + 1])
        {
            aIndex--;
        }
        else if (dp[aIndex + 1][bIndex + 1] == dp[aIndex + 1][bIndex])
        {
            bIndex--;
        }
    }
    while (!path.empty())
    {
        cout << path.top();
        path.pop();
    }
    return 0;
 }