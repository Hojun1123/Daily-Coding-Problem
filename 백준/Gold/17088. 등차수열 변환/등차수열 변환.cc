#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N;
int arr[100111];
int ans = 987654321;
void tt(int _prev, int _curr, int ss)
{
    int diff = _curr - _prev;
    int prev = _curr;
    int cnt0 = ss;
    for (int i = 2; i < N; ++i) {
        if (arr[i] - prev == diff) {
            prev = arr[i];
            continue;
        }
        if (arr[i] - 1 - prev == diff) {
            prev = arr[i] - 1;
            cnt0++;
            continue;
        }
        if (arr[i] + 1 - prev == diff) {
            prev = arr[i] + 1;
            cnt0++;
            continue;
        }
        return;
    }
    ans = min(ans, cnt0);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    // -1 0 1
    if (N == 1) {
        cout << 0;
        return 0;
    }
    tt(arr[0] - 1, arr[1] - 1, 2);
    tt(arr[0] - 1, arr[1], 1);
    tt(arr[0] - 1, arr[1] + 1, 2);

    tt(arr[0], arr[1] - 1, 1);
    tt(arr[0], arr[1], 0);
    tt(arr[0], arr[1] + 1, 1);

    tt(arr[0] + 1, arr[1] - 1, 2);
    tt(arr[0] + 1, arr[1], 1);
    tt(arr[0] + 1, arr[1] + 1, 2);
    cout << (ans > 98760000 ? -1 : ans);
    return 0;
}