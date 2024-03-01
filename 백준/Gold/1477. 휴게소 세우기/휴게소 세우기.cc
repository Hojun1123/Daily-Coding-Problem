#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <deque>
#include <unordered_map>
#include <cstring>
using namespace std;
int N, M, L;
int arr[50];
bool able(int n)
{
    int start = 0;
    int cnt = 0;
    for (int i = 0; i <= N; ++i)
    {
        int diff = arr[i] - start;
        if (diff % n == 0)
        {
            cnt += diff / n - 1;
        }
        else
        {
            cnt += diff / n;
        }
        start = arr[i];
    }
    return cnt <= M;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M >> L;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    arr[N] = L;
    int left = 1;
    int right = 1000;
    int mid;
    int m = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (able(mid))
        {
            right = mid - 1;
            m = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    cout << m;
    return 0;
}