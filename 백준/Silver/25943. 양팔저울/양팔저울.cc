#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <regex>
using namespace std;
//N
//입장에 필요한 최소 경험치와 1분마다 얻는 경험치
//특정
int N;
int l = 0;
int r = 0;
int main(int argc, char** argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int curr;
        cin >> curr;
        if (l <= r) l += curr;
        else r += curr;
    }
    //cout << l << " " << r << "\n";
    if (l == r) cout << 0;
    else {
        int cnt = 0;
        int diff = abs(l - r);
        int arr[7] = { 1, 2, 5, 10, 20, 50, 100 };
        for (int i = 6; i >= 0; --i) {
            while (arr[i] <= diff) {
                diff -= arr[i];
                cnt++;
            }
        }
        cout << cnt;
    }
    return 0;
}