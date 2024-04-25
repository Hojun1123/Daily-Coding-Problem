#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;
int N, K;
int arr[10001];
int diff[10001];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    int prev = arr[0];
    for (int i = 1; i < N; ++i) {
        diff[i - 1] = arr[i] - prev;
        prev = arr[i];
    }
    sort(diff, diff + N, greater<>());
    long long ans = 0;
    for (int i = K - 1; i < N - 1; ++i) ans = ans + diff[i];
    cout << ans;
    return 0;
}