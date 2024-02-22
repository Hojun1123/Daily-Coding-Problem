#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int N;
int arr[100000];
int a, b;
void bt(int left, int right)
{
    int answer = 2000000000;
    while (left < right)
    {
        int now = arr[left] + arr[right];
        if (abs(now) < answer)
        {
            a = arr[left];
            b = arr[right];
            answer = abs(now);
        }
        if (now < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> (arr[i]);
    }
    sort(arr, arr + N);
    bt(0, N -1 );
    cout << a << " " << b;
    return 0;
}