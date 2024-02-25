#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <deque>
#include <map>
#include <vector>
#include <sstream>
using namespace std;
int N, M;
long long arr[100000];
bool check(long long mid)
{
    long long cnt = 0;
    for (int i = 0; i < N; ++i)
    {
        cnt = cnt + mid / arr[i];
    }
    return cnt >= M;
}
long long bs(long long left, long long right)
{
    long long mid;
    long long m = -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (check(mid))
        {
            m = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return m;
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cout << bs(1, arr[0] * M);
    return 0;
}