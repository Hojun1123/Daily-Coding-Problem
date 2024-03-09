#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <list>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
#include <cstring>
#include <list>
using namespace std;
int N;
int arr[100000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int left = 0;
    int right = N - 1;
    int cnt = 0;
    int ansLeft = 0;
    int ansRight = N - 1;
    int minDiff = 2000000000;
    while (left < right)
    {
        int curr = arr[left] + arr[right];
        if (minDiff > abs(curr))
        {
            ansLeft = arr[left];
            ansRight = arr[right];
            minDiff = abs(curr);
        }
        if (curr < 0)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    cout << ansLeft << " " << ansRight;
    return 0;
}
