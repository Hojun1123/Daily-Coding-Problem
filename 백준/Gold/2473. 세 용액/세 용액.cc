#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
//25 000 000
int N;
int arr[5005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i)cin >> arr[i];
    sort(arr, arr + N);
    long long ans = 122100000000;
    int a, b, c;
    for (int i = 0; i < N - 2; ++i) {
        long long base = arr[i] * -1;
        int left = i + 1;
        int right = N - 1;
        while (left < right) {
            int curr = arr[left] + arr[right];
            if (ans > abs(base - curr)) {
                ans = abs(base - curr);
                a = arr[i];
                b = arr[left];
                c = arr[right];
            }
            if (curr < base) {
                left++;
            }
            else if (curr > base) {
                right--;
            }
            else {
                cout << arr[i] << " " << arr[left] << " " << arr[right];
                return 0;
            }

        }
    }
    cout << a << " " << b << " " << c;
    return 0;
}