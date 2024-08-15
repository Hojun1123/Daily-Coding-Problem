#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int n, k;
int arr[100001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    sort(arr, arr + n);
    int ans = 2100000000;
    int left = 0;
    int right = 1;
    while (right < n)
    {
        int ret = arr[right] - arr[left];
        if (ret < k) {
            right++;
        }
        else {
            ans = min(ans, ret);
            left++;
        }
    }
    cout << ans;
    return 0;
}