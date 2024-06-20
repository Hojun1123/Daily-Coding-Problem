#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
int N;
long long arr[4000][4];
long long a[16000000];
long long b[16000000];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3];
    }

    long long idx = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            a[idx++] = arr[i][0] + arr[j][1];
        }
    }
    
    idx = 0;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            b[idx++] = arr[i][2] + arr[j][3];
        }
    }

    sort(a, a + idx);
    sort(b, b + idx);

    long long cnt = 0;
    for (int i = 0; i < idx; ++i)
    {
        long long curr = a[i];
        long long* lptr = lower_bound(b, b + idx, -1L * curr);
        long long* rptr = upper_bound(b, b + idx, -1L * curr);
        cnt += rptr - lptr;
        
    }
    cout << cnt;
    return 0;
}