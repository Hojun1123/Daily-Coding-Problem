#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;
int N, K, M;
string arr[50];
unordered_map<string, int> um;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) cin >> arr[i];
    cin >> K;
    
    int p = K % 2;
    for (int i = 0; i < N; ++i) {
        int cnt = 0;
        for (int j = 0; j < M; ++j) {
            if (arr[i][j] == '0') {
                cnt++;
            }
        }
        if (cnt > K || cnt % 2 != p) continue;
        um[arr[i]]++;
    }
    int ans = 0;
    for (auto i : um)
    {
        ans = max(ans, i.second);
    }
    cout << ans;
    return 0;
}