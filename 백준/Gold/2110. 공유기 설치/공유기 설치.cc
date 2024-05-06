#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <cmath>
#include <unordered_map>
#include <cstring>
#include <algorithm>
using namespace std;
int N, C;
int arr[200000];
// 공유기 C개를 설치, 한 집에는 공유기를 하나만 설치.(0 ~ 10억)
// 가장 인접한 두 공유기 사이의 거리를 최대로.
bool check(int n)
{
    int cnt = 0;
    int prev = arr[0];
    for (int i = 1; i < N; ++i)
    {
        if (arr[i] - prev >= n) {
            cnt++;
            prev = arr[i];
        }
        if (cnt >= C - 1) return true;
    }
    return false;
}
int bs(int start, int end)
{
    int mid;
    int ret = -1;
    while (start < end)
    {
        mid = (start + end) / 2;
        if (check(mid))
        {
            ret = mid;
            start = mid + 1;
        }
        else end = mid;
    }
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> C;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    sort(arr, arr + N);
    cout << bs(0, 1000000001);
    return 0;
}