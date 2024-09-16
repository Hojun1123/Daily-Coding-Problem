#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int N, M;
int arr[500001];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    //1 3 4 5 9
    //13 459
    //134 59
    //a[1] - a[0] + a[4] - a[2] + a[6] - a[5]
    // 
    //a[2] + a[4] + a[6] - (a[0], a[3], a[5])
    //a[1] + a[4] + a[6] - (a[0], a[2], a[5])
    //a[1] + a[3] + a[6] - (a[0], a[2], a[4])
    long long left = 0;
    long long right = 0;
    long long ans = 200000000000000;
    right = right + arr[0];
    left = left + arr[2];
    for (int i = 3; i < N; i ++) {
        if (i % 2 == 0) {
            left = left + arr[i];
        }
        else {
            right = right + arr[i];
        }
    }
    //1 3 4 5 9
    // 4, 9 : 1, 5
    // 3, 9 : 1, 4
    //cout << left << " " << right << "\n";
    ans = min(ans, left - right);
    //cout << ans << "\n";
    for (int i = 2; i < N - 2; i += 2) {
        left = left - arr[i];
        left = left + arr[i - 1];
        right = right - arr[i + 1];
        right = right + arr[i];
        //cout << left << " " << right << "\n";
        ans = min(ans, left - right);
    }
    cout << ans;
}