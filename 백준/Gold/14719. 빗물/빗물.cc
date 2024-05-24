#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int H, W;
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> H >> W;
    int arr[500];
    for (int i = 0; i < W; ++i) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i < W - 1; ++i)
    {
        int left = 0, right = 0;
        for (int j = i - 1; j >= 0; --j)
        {
            left = max(left, arr[j]);
        }
        
        for (int j = i + 1; j < W; ++j)
        {
            right = max(right, arr[j]);
        }
        
        int r = min(left, right);
        if (r > arr[i]) ans += r - arr[i];
    }
    cout << ans;
    return 0;
}