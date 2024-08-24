#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, K;
int arr[300333];
int diff[300333];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    for (int i = 1; i < N; ++i) {
        diff[i - 1] = arr[i] - arr[i - 1];
    }
    sort(diff, diff + N - 1);
    long long ans = 0;
    for (int i = 0; i < N - K; ++i) ans += (long long)diff[i];
    cout << ans;
    return 0;
}