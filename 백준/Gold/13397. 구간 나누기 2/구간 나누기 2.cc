#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <string>
using namespace std;
int N, M;
int arr[5000];
int check(int n)
{
    int minv = arr[0];
    int maxv = arr[0];
    int cnt = 1;
    for (int i = 1; i < N; ++i)
    {
        if (arr[i] < minv) {
            minv = arr[i];
        }
        else if (arr[i] > maxv) {
            maxv = arr[i];
        }

        if ((maxv - minv) > n)
        {
            cnt++;
            maxv = minv = arr[i];
            if (cnt > M) return 0;
        }
    }
    return 1;
}
int bt(int left, int right)
{
    int r = -1;
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (check(mid))
        {
            right = mid;
            r = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return r;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    cout << bt(0, 50000000);
    return 0;
}