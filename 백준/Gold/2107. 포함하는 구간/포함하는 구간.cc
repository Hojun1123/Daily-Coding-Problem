#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
using namespace std;
int N;
struct ab {
    int a, b;
    bool operator<(ab o) const {
        if ((b - a) > (o.b - o.a))return true;
        else if (b - a < o.b - o.a) return false;
        return a < o.a;
    }
};
ab arr[25005];
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            arr[i].a = a;
            arr[i].b = b;
        }
        else {
            arr[i].b = a;
            arr[i].a = b;
        }
    }
    
    //
    int ans = 0;
    sort(arr, arr + N);
    // for (int i = 0; i < N; ++i) cout << arr[i].a << " " << arr[i].b << "\n";
    for (int i = 0; i < N; ++i) {
        int left = arr[i].a;
        int right = arr[i].b;
        int cnt = 0;
        for (int j = i + 1; j < N; ++j) {
            if (left <= arr[j].a && right >= arr[j].b) {
                cnt++;
            }
        }
        ans = max(cnt, ans);
    }
    cout << ans;
    return 0;
}