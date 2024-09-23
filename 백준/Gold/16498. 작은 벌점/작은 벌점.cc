#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int A, B, C;
vector<int> arr[3];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> A >> B>> C;
    int a;
    for (int i = 0; i < A; ++i) {
        cin >> a;
        arr[0].push_back(a);
    }
    for (int i = 0; i < B; ++i) {
        cin >> a;
        arr[1].push_back(a);
    }
    for (int i = 0; i < C; ++i) {
        cin >> a;
        arr[2].push_back(a);
    }
    for (int i = 0; i < 3; ++i)
        sort(arr[i].begin(), arr[i].end());

    int ans = 2100000000;
    for (int i = 0; i < A; ++i) {
        int num = arr[0][i];
        auto r1 = lower_bound(arr[1].begin(), arr[1].end(), num);
        auto r2 = lower_bound(arr[2].begin(), arr[2].end(), num);
        if (r1 == arr[1].end() || r2 == arr[2].end()) continue;
        ans = min(ans, max(*r1, *r2) - num);
    }
    for (int i = 0; i < B; ++i) {
        int num = arr[1][i];
        auto r1 = lower_bound(arr[0].begin(), arr[0].end(), num);
        auto r2 = lower_bound(arr[2].begin(), arr[2].end(), num);
        if (r1 == arr[0].end() || r2 == arr[2].end()) continue;
        ans = min(ans, max(*r1, *r2) - num);
    }
    for (int i = 0; i < C; ++i) {
        int num = arr[2][i];
        auto r1 = lower_bound(arr[0].begin(), arr[0].end(), num);
        auto r2 = lower_bound(arr[1].begin(), arr[1].end(), num);
        if (r1 == arr[0].end() || r2 == arr[1].end()) continue;
        ans = min(ans, max(*r1, *r2) - num);
    }
    cout << ans;
    return 0;
}