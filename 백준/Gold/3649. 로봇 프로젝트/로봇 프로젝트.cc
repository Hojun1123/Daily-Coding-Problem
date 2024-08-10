#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <stack>
using namespace std;
int N, X;
int arr[1000000];
void solve()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
    }
    // 1억 ~ 20억
    sort(arr, arr + N);
    X *= 10000000;
    int left = 0;
    int right = N - 1;
    while (left < right)
    {
        if (arr[left] + arr[right] == X) {
            cout << "yes " << arr[left] << ' ' << arr[right] << '\n';
            return;
        }
        else if (arr[left] + arr[right] > X) right--;
        else left++;
    }
    cout << "danger\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    while (cin >> X) {
        solve();
    }
    return 0;
}